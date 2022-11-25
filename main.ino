#include "Adafruit_NeoTrellis.h"
#include "./constants.h"
#include "./color_mapper.h"
#include "./startup_animation.h"
#include "./sequences.h"
#include "./key_handler.h"
#include "./init.h"
#include "./helpers.h"

void setup() {
  Serial.begin(9600);
  
  initTrellis();
  initAnalogPins();
}

void loop() {
  switchButton(analogRead(PLAY_BUTTON_PIN) < 1000, playPause);

  trellis.read();
  
  displaySequence(selectedSequence);
  
  if(play){
    runSequence(selectedSequence, play);
  }

   delay(20); // resolution of around 60hz
}
