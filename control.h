

#ifndef CONTROL
#define CONTROL

#include "hal.h"

enum { TRIGGER_AUTO, TRIGGER_NORM, TRIGGER_SINGLE };

extern uint8_t triggerType;


void setTriggerType(uint8_t tType);

void controlLoop(void);	

#endif
