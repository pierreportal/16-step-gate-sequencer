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
