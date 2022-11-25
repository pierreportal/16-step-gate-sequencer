
bool detectKeyPress(keyEvent evt) {
  return evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING;
}

bool detectKeyReleased(keyEvent evt) {
  return evt.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING;
}

void turnOffPadLight(keyEvent evt) {
  trellis.pixels.setPixelColor(evt.bit.NUM, 0); //off falling
}

uint32_t rainbowColorIndex(keyEvent evt) {
  return Wheel(map(evt.bit.NUM, 0, trellis.pixels.numPixels(), 0, 255));
}

int SELECTED_SEQUENCE = 0;

bool MODE_PAD_A_ACTIVE = false;
bool MODE_PAD_B_ACTIVE = false;
bool MODE_PAD_C_ACTIVE = false;
bool MODE_PAD_D_ACTIVE = false;

void keyPressInModeA(keyEvent evt){
  int padIndex = evt.bit.NUM;
  Serial.println("Mode A --- ");
  Serial.print(padIndex);
}

void triggerPad(keyEvent evt) {
  int padIndex = evt.bit.NUM;
  if(MODE_PAD_A_ACTIVE) {
    keyPressInModeA(evt);
  }
  Serial.println(padIndex);
  trellis.pixels.setPixelColor(padIndex, rainbowColorIndex(evt)); //on rising
}

void releasePad(keyEvent evt) {
  turnOffPadLight(evt);
}
