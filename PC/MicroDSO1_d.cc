CPWindow1::CPWindow1(void)
{
//lxrad automatic generated block start, don't edit below!
  SetFOwner(this);
  SetClass(lxT("CPWindow"));
  SetName(lxT("window1"));
  SetTag(0);
  SetX(395);
  SetY(167);
  SetWidth(595);
  SetHeight(404);
  SetHint(lxT(""));
  SetEnable(1);
  SetVisible(1);
  SetColor(lxT("#000001"));
  SetPopupMenu(NULL);
  SetTitle(lxT("MicroDSO"));
  SetOverrideRedirect(0);
  EvOnCreate=EVONCREATE & CPWindow1::_EvOnCreate;
  EvOnDestroy=EVONDESTROY & CPWindow1::_EvOnDestroy;
  EvOnShow=EVONSHOW & CPWindow1::_EvOnShow;
  //draw1
  draw1.SetFOwner(this);
  draw1.SetClass(lxT("CDraw"));
  draw1.SetName(lxT("draw1"));
  draw1.SetTag(0);
  draw1.SetX(135);
  draw1.SetY(33);
  draw1.SetWidth(320);
  draw1.SetHeight(240);
  draw1.SetHint(lxT(""));
  draw1.SetEnable(1);
  draw1.SetVisible(1);
  draw1.SetColor(lxT("#000001"));
  draw1.SetPopupMenu(NULL);
  draw1.SetTransparent(0);
  draw1.SetImgFileName(lxT(""));
  CreateChild(&draw1);
  //button1
  button1.SetFOwner(this);
  button1.SetClass(lxT("CButton"));
  button1.SetName(lxT("button1"));
  button1.SetTag(0);
  button1.SetX(474);
  button1.SetY(200);
  button1.SetWidth(65);
  button1.SetHeight(28);
  button1.SetHint(lxT(""));
  button1.SetEnable(1);
  button1.SetVisible(1);
  button1.SetColor(lxT("#000001"));
  button1.SetPopupMenu(NULL);
  button1.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::button1_EvMouseButtonPress;
  button1.EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow1::button1_EvMouseButtonRelease;
  button1.SetText(lxT("Sel"));
  CreateChild(&button1);
  //button2
  button2.SetFOwner(this);
  button2.SetClass(lxT("CButton"));
  button2.SetName(lxT("button2"));
  button2.SetTag(0);
  button2.SetX(476);
  button2.SetY(143);
  button2.SetWidth(65);
  button2.SetHeight(28);
  button2.SetHint(lxT(""));
  button2.SetEnable(1);
  button2.SetVisible(1);
  button2.SetColor(lxT("#000001"));
  button2.SetPopupMenu(NULL);
  button2.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::button2_EvMouseButtonPress;
  button2.EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow1::button2_EvMouseButtonRelease;
  button2.SetText(lxT("+"));
  CreateChild(&button2);
  //button3
  button3.SetFOwner(this);
  button3.SetClass(lxT("CButton"));
  button3.SetName(lxT("button3"));
  button3.SetTag(0);
  button3.SetX(475);
  button3.SetY(94);
  button3.SetWidth(65);
  button3.SetHeight(28);
  button3.SetHint(lxT(""));
  button3.SetEnable(1);
  button3.SetVisible(1);
  button3.SetColor(lxT("#000001"));
  button3.SetPopupMenu(NULL);
  button3.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::button3_EvMouseButtonPress;
  button3.EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow1::button3_EvMouseButtonRelease;
  button3.SetText(lxT("-"));
  CreateChild(&button3);
  //button4
  button4.SetFOwner(this);
  button4.SetClass(lxT("CButton"));
  button4.SetName(lxT("button4"));
  button4.SetTag(0);
  button4.SetX(475);
  button4.SetY(47);
  button4.SetWidth(65);
  button4.SetHeight(28);
  button4.SetHint(lxT(""));
  button4.SetEnable(1);
  button4.SetVisible(1);
  button4.SetColor(lxT("#000001"));
  button4.SetPopupMenu(NULL);
  button4.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::button4_EvMouseButtonPress;
  button4.EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow1::button4_EvMouseButtonRelease;
  button4.SetText(lxT("Ok"));
  CreateChild(&button4);
  //timer1
  timer1.SetFOwner(this);
  timer1.SetClass(lxT("CTimer"));
  timer1.SetName(lxT("timer1"));
  timer1.SetTag(0);
  timer1.SetTime(100);
  timer1.SetRunState(0);
  timer1.EvOnTime= EVONTIME & CPWindow1::timer1_EvOnTime; 
  CreateChild(&timer1);
  //button5
  button5.SetFOwner(this);
  button5.SetClass(lxT("CButton"));
  button5.SetName(lxT("button5"));
  button5.SetTag(0);
  button5.SetX(387);
  button5.SetY(286);
  button5.SetWidth(65);
  button5.SetHeight(28);
  button5.SetHint(lxT(""));
  button5.SetEnable(1);
  button5.SetVisible(1);
  button5.SetColor(lxT("#000001"));
  button5.SetPopupMenu(NULL);
  button5.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow1::button5_EvMouseButtonPress;
  button5.EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow1::button5_EvMouseButtonRelease;
  button5.SetText(lxT("Reset"));
  CreateChild(&button5);
  //combo1
  combo1.SetFOwner(this);
  combo1.SetClass(lxT("CCombo"));
  combo1.SetName(lxT("combo1"));
  combo1.SetTag(0);
  combo1.SetX(24);
  combo1.SetY(79);
  combo1.SetWidth(80);
  combo1.SetHeight(26);
  combo1.SetHint(lxT(""));
  combo1.SetEnable(1);
  combo1.SetVisible(1);
  combo1.SetColor(lxT("#000001"));
  combo1.SetPopupMenu(NULL);
  combo1.SetItems(lxT("GND,AC,DC,"));
  combo1.SetText(lxT("DC"));
  combo1.SetReadOnly(0);
  combo1.EvOnComboChange=EVONCOMBOCHANGE & CPWindow1::combo1_EvOnComboChange;
  CreateChild(&combo1);
  //combo2
  combo2.SetFOwner(this);
  combo2.SetClass(lxT("CCombo"));
  combo2.SetName(lxT("combo2"));
  combo2.SetTag(0);
  combo2.SetX(24);
  combo2.SetY(136);
  combo2.SetWidth(80);
  combo2.SetHeight(26);
  combo2.SetHint(lxT(""));
  combo2.SetEnable(1);
  combo2.SetVisible(1);
  combo2.SetColor(lxT("#000001"));
  combo2.SetPopupMenu(NULL);
  combo2.SetItems(lxT("1V,0.1V,10mV,"));
  combo2.SetText(lxT("1V"));
  combo2.SetReadOnly(0);
  combo2.EvOnComboChange=EVONCOMBOCHANGE & CPWindow1::combo2_EvOnComboChange;
  CreateChild(&combo2);
  //combo3
  combo3.SetFOwner(this);
  combo3.SetClass(lxT("CCombo"));
  combo3.SetName(lxT("combo3"));
  combo3.SetTag(0);
  combo3.SetX(25);
  combo3.SetY(191);
  combo3.SetWidth(80);
  combo3.SetHeight(26);
  combo3.SetHint(lxT(""));
  combo3.SetEnable(1);
  combo3.SetVisible(1);
  combo3.SetColor(lxT("#000001"));
  combo3.SetPopupMenu(NULL);
  combo3.SetItems(lxT("X5,X2,X1,"));
  combo3.SetText(lxT("X1"));
  combo3.SetReadOnly(0);
  combo3.EvOnComboChange=EVONCOMBOCHANGE & CPWindow1::combo3_EvOnComboChange;
  CreateChild(&combo3);
  //label1
  label1.SetFOwner(this);
  label1.SetClass(lxT("CLabel"));
  label1.SetName(lxT("label1"));
  label1.SetTag(0);
  label1.SetX(25);
  label1.SetY(58);
  label1.SetWidth(60);
  label1.SetHeight(20);
  label1.SetHint(lxT(""));
  label1.SetEnable(1);
  label1.SetVisible(1);
  label1.SetColor(lxT("#000001"));
  label1.SetPopupMenu(NULL);
  label1.SetText(lxT("CPL"));
  label1.SetAlign(1);
  CreateChild(&label1);
  //label2
  label2.SetFOwner(this);
  label2.SetClass(lxT("CLabel"));
  label2.SetName(lxT("label2"));
  label2.SetTag(0);
  label2.SetX(25);
  label2.SetY(113);
  label2.SetWidth(60);
  label2.SetHeight(20);
  label2.SetHint(lxT(""));
  label2.SetEnable(1);
  label2.SetVisible(1);
  label2.SetColor(lxT("#000001"));
  label2.SetPopupMenu(NULL);
  label2.SetText(lxT("SEN1"));
  label2.SetAlign(1);
  CreateChild(&label2);
  //label3
  label3.SetFOwner(this);
  label3.SetClass(lxT("CLabel"));
  label3.SetName(lxT("label3"));
  label3.SetTag(0);
  label3.SetX(26);
  label3.SetY(169);
  label3.SetWidth(60);
  label3.SetHeight(20);
  label3.SetHint(lxT(""));
  label3.SetEnable(1);
  label3.SetVisible(1);
  label3.SetColor(lxT("#000001"));
  label3.SetPopupMenu(NULL);
  label3.SetText(lxT("SEN2"));
  label3.SetAlign(1);
  CreateChild(&label3);
  //checkbox1
  checkbox1.SetFOwner(this);
  checkbox1.SetClass(lxT("CCheckBox"));
  checkbox1.SetName(lxT("checkbox1"));
  checkbox1.SetTag(0);
  checkbox1.SetX(279);
  checkbox1.SetY(285);
  checkbox1.SetWidth(95);
  checkbox1.SetHeight(25);
  checkbox1.SetHint(lxT(""));
  checkbox1.SetEnable(1);
  checkbox1.SetVisible(1);
  checkbox1.SetColor(lxT("#000001"));
  checkbox1.SetPopupMenu(NULL);
  checkbox1.SetText(lxT("Trigged"));
  checkbox1.SetCheck(0);
  CreateChild(&checkbox1);
  /*#Others*/
//lxrad automatic generated block end, don't edit above!
};
