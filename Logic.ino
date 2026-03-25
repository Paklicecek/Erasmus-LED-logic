int ledPins[] = {27, 14, 12, 13, 32, 33, 25, 19, 5, 4, 2, 15};
const int ledAmount = 12;
const int buttonPin = 26;

void setup() {
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT_PULLUP);

  for (int i = 0; i < ledAmount; i++) {
    ledcAttach(ledPins[i], 5000, 8);
    ledcWrite(ledPins[i], 0);
  }
}

void loop() {
  randomAnimation();
}

void checkSleepButton() {
  if (digitalRead(buttonPin) == LOW) {
    turnAllOff();
    while(digitalRead(buttonPin) == LOW) {
      delay(10);
    }
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_26, 0);
    esp_deep_sleep_start();
  }
}

void smartDelay(int waitTime) {
  unsigned long startTime = millis();
  while (millis() - startTime < waitTime) {
    checkSleepButton();
    delay(10);
  }
}

void randomAnimation() {
  int chance = random(1, 101); 
  if (chance >= 97 ) {
    for(int i = 0; i < 3; i++){
      oneByOne();
      smartDelay(300);
      fadeAway();
      smartDelay(500);
    }
  } 
  else if (chance >= 94) {
    for(int i = 0; i < 4; i++){
      oddEven();
    }
    smartDelay(1000);
  } 
  else {
    fadeIn();
    smartDelay(500);
    fullCircle();
    smartDelay(1000);
  }
}

void fadeIn(){
  for (int b = 0; b <= 170; b++) {
    for (int i = 0; i < ledAmount; i++) ledcWrite(ledPins[i], b);
    smartDelay(20);
  }
  smartDelay(500);
  for (int b = 170; b >= 0; b--) {
    for (int i = 0; i < ledAmount; i++) ledcWrite(ledPins[i], b);
    smartDelay(20);
  }
  smartDelay(500);
}

void fullCircle(){
  for(int i = 0; i < ledAmount; i++){
    ledcWrite(ledPins[i], 255);
  }
  smartDelay(300);
  turnAllOff();
}

void turnAllOff(){
  for(int i = 0; i < ledAmount; i++){
    ledcWrite(ledPins[i], 0);
  }
}

void oneByOne(){
  for(int i = 0; i < ledAmount; i++){
    ledcWrite(ledPins[i], 255);
    smartDelay(67);
  }
}

void fadeAway(){
  for(int i = ledAmount - 1; i >= 0; i--){
    ledcWrite(ledPins[i], 0);
    smartDelay(67);
  }
}

void oddEven(){
  for(int i = 0; i < ledAmount; i++){
    if(i % 2 == 0) ledcWrite(ledPins[i], 255);
    else ledcWrite(ledPins[i], 0);
  }
  smartDelay(500);
  for(int i = 0; i < ledAmount; i++){
    if(i % 2 == 0) ledcWrite(ledPins[i], 0);
    else ledcWrite(ledPins[i], 255);
  }
  smartDelay(500);
  turnAllOff();
}