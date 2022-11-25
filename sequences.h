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
  for(int i=0; i < 16; i++){
    if(sequences[sequenceIndex][i]){
      trellis.pixels.setPixelColor(i, COLOR_PURPLE);
    }
  }
  trellis.pixels.show();
}

int index = 0;

void resetKeyIndex(){
  index = 0;
}

bool play = false;

void playPause(){
  resetKeyIndex();
  play = not play;
}

void runSequence(int sequenceIndex, bool playing/*, int clockSignal*/){
  bool indexState = sequences[sequenceIndex][index];
  int c;
  if(indexState){
    c = COLOR_PURPLE;
  } else {
    c = COLOR_NONE;
  }
  
  trellis.pixels.setPixelColor(index, COLOR_BLUE);
  trellis.pixels.show();
  delay(50);

  trellis.pixels.setPixelColor(index, c);
  trellis.pixels.show();
  delay(50);
    
  index = (index + 1) % 16;
}

void toggleSequenceKey(int keyIndex, int sequenceIndex){
  sequences[sequenceIndex][keyIndex] = not sequences[sequenceIndex][keyIndex];
}
