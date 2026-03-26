int ledPins[] = {21, 14, 12, 13, 32, 33, 25, 19, 5, 4, 2, 15};

// Piko white table
// 32 is instead of 18 for one table, fix before any publishing
// Wooden table Gayboy
// 21 is insteaed of 27 for one table, fix before any publishing
const int ledAmount = 12;
const int buttonPin = 26;

void setup() {
  randomSeed(analogRead(36));
  pinMode(buttonPin, INPUT_PULLDOWN);
  for (int i = 0; i < ledAmount; i++) {
    ledcAttach(ledPins[i], 5000, 8);
    ledcWrite(ledPins[i], 0);
  }
}

void loop() {
  randomAnimation();
}

void checkPowerButton() {
  if (digitalRead(buttonPin) == LOW) {
    turnAllOff();
    
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
}

void smartDelay(int waitTime) {
  for (int i = 0; i < waitTime; i++) {
    checkPowerButton(); 
    delay(1);
  }
}

void randomAnimation() {
  int chance = random(1, 101); 
  if (chance >= 75) {
    oneByOne();
    smartDelay(1000);
    fadeAway();
    smartDelay(1000);
  } 
  else if (chance >= 50) {
    for(int i = 0; i < 4; i++){
      oddEven();
    }
    smartDelay(1000);
  } 
  else if (chance >= 25){
    fadeIn();
    smartDelay(1000);
  }
  else{
    fullCircle();
    smartDelay(1000);
  }
}

void fadeIn(){
  for (int b = 0; b <= 170; b++) {
    for (int i = 0; i < ledAmount; i++) ledcWrite(ledPins[i], b);
    smartDelay(30);
  }
  smartDelay(1000);
  for (int b = 170; b >= 0; b--) {
    for (int i = 0; i < ledAmount; i++) ledcWrite(ledPins[i], b);
    smartDelay(30);
  }
  smartDelay(1000);
}

void fullCircle(){
  for(int i = 0; i < ledAmount; i++){
    ledcWrite(ledPins[i], 255);
  }
  smartDelay(4000);
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
    smartDelay(400);
  }
}

void fadeAway(){
  for(int i = ledAmount - 1; i >= 0; i--){
    ledcWrite(ledPins[i], 0);
    smartDelay(400);
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