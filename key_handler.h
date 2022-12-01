bool A_modePadActive = false;
bool B_modePadActive = false;
bool C_modePadActive = false; // select sequence
bool D_modePadActive = false; 

int pressedKey;
int releasedKey;

bool detectKeyPress(keyEvent evt) {
  return evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING;
}

bool detectKeyReleased(keyEvent evt) {
  return evt.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING;
}

void turnOffPadLight(keyEvent evt) {
  trellis.pixels.setPixelColor(evt.bit.NUM, COLOR_NONE);
}

void triggerSpecialTriggerKeys(int padIndex){
  if(pressedKey == MODE_PAD_C_INDEX) {
    //toggleSequenceKey(MODE_PAD_C_INDEX, selectedSequence);
    C_modePadActive = true;
  
  } else {
    pressedKey = padIndex;
  }
}

void releaseSpecialTriggerKeys(int keyIndex){
  if(keyIndex == MODE_PAD_C_INDEX) {
    C_modePadActive = false;
  }
  if(keyIndex == MODE_PAD_D_INDEX) {
    D_modePadActive = false;
  }
}

void keyPressInModeC(int keyIndex){
  if(keyIndex > 3) {
    return;
  }
  selectedSequence = keyIndex;
  displaySequence(keyIndex);
  toggleSequenceKey(MODE_PAD_C_INDEX, selectedSequence);
}


void triggerPad(keyEvent evt) {
  int padIndex = evt.bit.NUM;

  triggerSpecialTriggerKeys(padIndex);
  
  if(C_modePadActive) {
    trellis.pixels.setPixelColor(padIndex, COLOR_MODE_KEY); //on rising
  } else {
    trellis.pixels.setPixelColor(padIndex, COLOR_PINK); //on rising    
  }
}

void releasePad(keyEvent evt) {
  int padIndex = evt.bit.NUM;
  releasedKey = padIndex;
  
  if(C_modePadActive) {
    keyPressInModeC(padIndex);
  } else {
    toggleSequenceKey(padIndex, selectedSequence);
  }

  turnOffPadLight(evt);
  releaseSpecialTriggerKeys(evt.bit.NUM);
}

TrellisCallback blink(keyEvent evt){
  if (detectKeyPress(evt)) {
    
    triggerPad(evt);

  } else if (detectKeyReleased(evt)) {
  

    releasePad(evt);
  }
  trellis.pixels.show();
  return 0;
}
