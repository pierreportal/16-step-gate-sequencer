#include "Adafruit_NeoTrellis.h"
#include "./constants.h"
#include "./color_mapper.h"
#include "./startup_animation.h"
#include "./helpers.h"
#include "./sequences.h"
#include "./key_handler.h"
#include "./init.h"


void setup() {
  Serial.begin(9600);
  
  initTrellis();
  initAnalogPins();
  
}

void clockTrigger(){
  blinkLed(CLOCK_LED_PIN, 0);
  if(play){
    runSequence(index, play);
    moveSequenceIndex();
    
  }
}

void loop() {

  
  
  switchButton(analogRead(PLAY_BUTTON_PIN) < 1000, playPause);

  int clockValue = analogRead(CLOCK_INPUT_PIN) * (5.0 / 1023.0);
  
  clockSignalIn(clockValue > 0, clockTrigger);

  trellis.read();
  
  displaySequence(selectedSequence);

  delay(20); // resolution of around 60hz
}
