
#include "hal.h" 
#include "variables.h"
#include "encoder.h"
#include "interface.h"
#include "capture.h"
#include "display.h"

int16_t trigLevel = 0;

void setADC(void);
void blinkLED(void);
void initScanTimeout(void);

// ------------------------
void initIO(void)	{
// ------------------------
	// set pin I/O direction
	pinMode(BOARD_LED, OUTPUT);
	pinMode(AN_CH1, INPUT_ANALOG);
	pinMode(AN_CH2, INPUT_ANALOG);
#ifndef HWDEBUG
	pinMode(DG_CH1, INPUT_PULLDOWN);
	pinMode(DG_CH2, INPUT_PULLDOWN);
#endif
	pinMode(TRIGGER_IN, INPUT_PULLUP);
	
	// calibrate the ADC channels at startup
	adc_calibrate(ADC1);
	adc_calibrate(ADC2);
	setADC();

	// start 1KHz square wave
	pinMode(TEST_WAVE_PIN, PWM);
	Timer3.setPeriod(1000);
	pwmWrite(TEST_WAVE_PIN, 17850);
	DBG_PRINTLN("Test square wave started");
	
	// input button and encoder
	pinMode(ENCODER_SW, INPUT_PULLUP);
	pinMode(ENCODER_A, INPUT_PULLUP);
	pinMode(ENCODER_B, INPUT_PULLUP);
	pinMode(BTN4, INPUT_PULLUP);
	
	attachInterrupt(ENCODER_SW, readESwitchISR, FALLING);
	attachInterrupt(BTN4, btn4ISR, CHANGE);
	
#ifdef USE_ENCODER
	attachInterrupt(ENCODER_A, readEncoderISR, CHANGE);
	attachInterrupt(ENCODER_B, readEncoderISR, CHANGE);
#else
	attachInterrupt(ENCODER_A, readASwitchISR, FALLING);
	attachInterrupt(ENCODER_B, readBSwitchISR, FALLING);
#endif	

	// init trigger level PWM
	// start 20KHz square wave on trigger out reference and negative v gen
	Timer4.setPeriod(50);
	pinMode(TRIGGER_LEVEL, PWM);
	pinMode(VGEN, PWM);
	pwmWrite(VGEN, 700);
	
	blinkLED();
	
	// init scan timeout timer
	initScanTimeout();
}




// ------------------------
void setADC(void)	{
// ------------------------
	int pinMapADCin1 = AN_CH1_channel;
	int pinMapADCin2 = AN_CH2_channel;
	
	// opamp is low impedance, set fastest sampling 
	adc_set_sample_rate(ADC1, ADC_SMPR_1_5);
	adc_set_sample_rate(ADC2, ADC_SMPR_1_5);

	adc_set_reg_seqlen(ADC1, 1);
	//ADC1->regs->SQR3 = pinMapADCin1;
        adc_set_channel(ADC1,  pinMapADCin1 );
	// set ADC1 continuous mode
	//ADC1->regs->CR2 |= ADC_CR2_CONT; 	
	// set ADC2 in regular simultaneous mode
	//ADC1->regs->CR1 |= 0x60000; 		
	//ADC1->regs->CR2 |= ADC_CR2_SWSTART;
        adc_set_mode(ADC1, 0x60000 , ADC_CR2_SWSTART | ADC_CR2_CONT);
    
	// set ADC2 continuous mode
	//ADC2->regs->CR2 |= ADC_CR2_CONT; 	
        adc_set_mode(ADC2, 0 , ADC_CR2_CONT);
	//ADC2->regs->SQR3 = pinMapADCin2;
        adc_set_channel(ADC2,  pinMapADCin2 );
}



// ------------------------
void blinkLED(void)	{
// ------------------------
	LED_ON;
	delay(10);
	LED_OFF;
}



// ------------------------
void initScanTimeout(void)	{
// ------------------------
	Timer2.setChannel1Mode(TIMER_OUTPUTCOMPARE);
	Timer2.pause();
	Timer2.setCompare1(1);
	Timer2.attachCompare1Interrupt(scanTimeoutISR);
}



// ------------------------
int16_t getTriggerLevel(void)	{
// ------------------------
	return trigLevel;
}



// ------------------------
void setTriggerLevel(int16_t tLvl)	{
// ------------------------
	// 600 = 20% duty
	// 1800 = 50%
	trigLevel = tLvl;
	pwmWrite(TRIGGER_LEVEL, 1800 + trigLevel);
}





// ------------------------
void readInpSwitches(void)	{
// ------------------------
	static uint8_t couplingOld, rangeOld;

	uint16_t cpl, pos1, pos2;
	//adc_reg_map *ADC1regs = ADC1->regs;

	// ADC1 and ADC2 are free running at max speed
	
	// change to switch 1 
	//ADC1regs->SQR3 = PIN_MAP[VSENSSEL2].adc_channel;
  adc_set_channel(ADC1, VSENSSEL2_channel );
	delayMicroseconds(100);
	//pos2 = (uint16_t) (ADC1regs->DR & ADC_DR_DATA);
	pos2 = adc_read(ADC1);
  
	//ADC1regs->SQR3 = PIN_MAP[VSENSSEL1].adc_channel;
  adc_set_channel(ADC1, VSENSSEL1_channel );
	delayMicroseconds(100);
	//pos1 = (uint16_t) (ADC1regs->DR & ADC_DR_DATA);
  pos1 = adc_read(ADC1);
	
	//ADC1regs->SQR3 = PIN_MAP[CPLSEL].adc_channel;
  adc_set_channel(ADC1, CPLSEL_channel );
	delayMicroseconds(100);
	//cpl = (uint16_t) (ADC1regs->DR & ADC_DR_DATA);
  cpl = adc_read(ADC1);
	
	if(cpl < 400)
		couplingPos = CPL_GND;
	else if(cpl < 2000)
		couplingPos = CPL_AC;
	else
		couplingPos = CPL_DC;
	
	if(pos1 < 400)
		rangePos = RNG_1V;
	else if(pos1 < 2000)
		rangePos = RNG_0_1V;
	else
		rangePos = RNG_10mV;
	
	if(pos2 < 400)
		rangePos -= 2;
	else if(pos2 < 2000)
		rangePos -= 1;
	else
		rangePos -= 0;
	
	// check if switch position changed from previous snap
	if(couplingPos != couplingOld)	{
		couplingOld = couplingPos;
		repaintLabels();
	}
	
	if(rangePos != rangeOld)	{
		rangeOld = rangePos;
		repaintLabels();
	}
	
	// read the negative voltage generator
	// ***
	
	// switch ADC1 back to capture channel
	//ADC1regs->SQR3 = PIN_MAP[AN_CH1].adc_channel;
        adc_set_channel(ADC1,  AN_CH1_channel );
	delayMicroseconds(100);
}
