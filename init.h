void initTrellis() {
  if (!trellis.begin()) {
    Serial.println("Could not start trellis, check wiring?");
    
    while(1) delay(1);
    
  } else {
    Serial.println("NeoPixel Trellis started");
  }

  for(int i=0; i<NEO_TRELLIS_NUM_KEYS; i++){
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_RISING);
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_FALLING);
    trellis.registerCallback(i, blink);
  }

  startupAnimation();
}

void initAnalogPins(){
  pinMode(PLAY_BUTTON_PIN, INPUT_PULLUP);
  pinMode(CLOCK_INPUT_PIN, INPUT_PULLUP);
  pinMode(CLOCK_LED_PIN, OUTPUT);
  pinMode(VOICE_A_PIN, OUTPUT);
  pinMode(VOICE_B_PIN, OUTPUT);
  pinMode(VOICE_C_PIN, OUTPUT);
  pinMode(VOICE_D_PIN, OUTPUT);
}
