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

void setSequence(int sequenceIndex){
  for(int i=0; i < 16; i++){
    if(sequences[sequenceIndex][i]){
      trellis.pixels.setPixelColor(i, COLOR_PURPLE);
    }
  }
  trellis.pixels.show();
}

int index = 0;

void runSequence(int sequenceIndex, bool playing/*, int clockSignal*/){
  bool indexState = sequences[sequenceIndex][index];
  int c;
  if(indexState){
    c = COLOR_PURPLE;
  } else {
    c = COLOR_NONE;
  }
  
  trellis.pixels.setPixelColor(index, COLOR_PURPLE);
  trellis.pixels.show();
  delay(50);

  trellis.pixels.setPixelColor(index, c);
  trellis.pixels.show();
  delay(50);
    
  index = (index + 1) % 16;
}


void toggleKey(int keyIndex, int sequenceIndex){
  sequences[sequenceIndex][keyIndex] = not sequences[sequenceIndex][keyIndex];
}
