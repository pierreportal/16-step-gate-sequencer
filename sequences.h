int selectedSequence = 0;

bool sequences[4][16] = {
  {
    false, true, false, false,
    false, false, true, false, 
    false, false, true, false, 
    true, false, false, false
  },
    {
    false, false, false, false,
    false, false, false, false, 
    false, false, false, false, 
    false, false, false, false
  },
    {
    false, false, false, false,
    false, false, false, false, 
    false, false, false, false, 
    false, false, false, false
  },
    {
    false, false, false, false,
    false, false, false, false, 
    false, false, false, false, 
    false, false, false, false
  }
};

void displaySequence(int sequenceIndex){
  int c;
  
  for(int i=0; i < 16; i++){
    if(sequences[sequenceIndex][i]){
      trellis.pixels.setPixelColor(i, Wheel(map(sequenceIndex, 0, 4, 0, 255)));
    } else {
      trellis.pixels.setPixelColor(i, COLOR_NONE);
    }
  }
  trellis.pixels.show();
}

int index = 0;

void resetKeyIndex(){
  index = 0;
}

void moveSequenceIndex(){
  index = (index + 1) % 16;
}

bool play = false;

void playPause(){
  resetKeyIndex();
  play = not play;
}

void sendSignal(int voiceIndex){
  if(voiceIndex == 0){
    blinkLed(VOICE_A_PIN, 0);
  }
  if(voiceIndex == 1){
    blinkLed(VOICE_B_PIN, 0);
  }
  if(voiceIndex == 2){
    blinkLed(VOICE_C_PIN, 0);
  }
  if(voiceIndex == 3){
    blinkLed(VOICE_D_PIN, 0);
  }
}

void runSequence(int keyIndex, bool playing/*, int clockSignal*/){
  int indexColor;
  for(int i=0; i < 4; i++) {
    bool indexState = sequences[i][keyIndex];

    
    
    if(indexState){
      indexColor = COLOR_PURPLE;
      sendSignal(i);
    } else {
      indexColor = 0xffffff;
    }
      
  }
  
  
  
  trellis.pixels.setPixelColor(keyIndex, indexColor);
  trellis.pixels.show();
}

void toggleSequenceKey(int keyIndex, int sequenceIndex){
  sequences[sequenceIndex][keyIndex] = not sequences[sequenceIndex][keyIndex];
}
