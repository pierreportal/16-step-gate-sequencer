bool switcher = true;
void switchButton(bool trigger, void (*callback)(void)){
  
  if(trigger and switcher){
    switcher = false;
    callback();
  }
  if(not trigger and not switcher){
    switcher = true;
  }
}


bool clockSignalSwitcher = true;
void clockSignalIn(bool trigger, void (*callback)(void)){
  if(trigger and clockSignalSwitcher){
    clockSignalSwitcher = false;
    callback();
  }
  if(not clockSignalSwitcher and not trigger){
    clockSignalSwitcher = true;
  }
}

void blinkLed(int pin, int delayTime){
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
}
