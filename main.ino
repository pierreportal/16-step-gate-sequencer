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


void setup() {
  init(blink);
}

void loop() {
  trellis.read();
  delay(20); // resolution of around 60hz
}
