#include "Adafruit_NeoTrellis.h"
#include "./constants.h"
#include "./color_mapper.h"
#include "./startup_animation.h"
#include "./sequences.h"
#include "./init.h"
#include "./key_handler.h"

TrellisCallback blink(keyEvent evt){
  int padIndex = evt.bit.NUM;
  
  if (detectKeyPress(evt)) {
    if(padIndex == MODE_PAD_A_INDEX) {
      MODE_PAD_A_ACTIVE = true;
    }  
    triggerPad(evt);
  } else if (detectKeyReleased(evt)) {
    if(padIndex == MODE_PAD_A_INDEX) {
      MODE_PAD_A_ACTIVE = false;
    }
    releasePad(evt);
  }
  trellis.pixels.show();
  return 0;
}

bool play = false;

bool switcher = true;


void setup() {
  init(blink);
}


void loop() {
  
  int playButtonValue = analogRead(PLAY_BUTTON_PIN);
  
  bool trigger = playButtonValue < 1000;
  
  if(trigger and switcher){
    play = not play;
    Serial.println(play);
    switcher = false;
  }

  if(not trigger and not switcher) {
    switcher = true;
  }
  
  trellis.read();
  delay(20); // resolution of around 60hz
}
