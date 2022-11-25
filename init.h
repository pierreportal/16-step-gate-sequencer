void init(TrellisCallback cb) {
  Serial.begin(9600);

  pinMode(PLAY_BUTTON_PIN, INPUT_PULLUP);
  
  if (!trellis.begin()) {
    Serial.println("Could not start trellis, check wiring?");
    
    while(1) delay(1);
    
  } else {
    Serial.println("NeoPixel Trellis started");
  }

  //activate all keys and set callbacks
  for(int i=0; i<NEO_TRELLIS_NUM_KEYS; i++){
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_RISING);
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_FALLING);
    trellis.registerCallback(i, cb);
  }

  //do a little animation to show we're on
  startupAnimation();
}
