int led1=12;
int led2=11;
int pushButton=2;
int buttonState;
int led1State;
int led2State;
int dumbState;
unsigned long previous, current;
long interval;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
  led1State=LOW;
  led2State=HIGH;
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
  interval=5000;
  previous=0; 
}

void loop() {
  current=millis();
  buttonState=digitalRead(pushButton);
  if(current-previous > interval) {
  previous=current;
  if(led1State==LOW){
    led1State=HIGH;
    led2State=LOW;
  }
  else {
    led1State=LOW;
    led2State=HIGH;
  }
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
 }
 else if(buttonState==LOW) {
  previous=0;
  /*dumbState=led1State;
  led1State !=led2State;
  led2State !=dumbState; */
  if(led1State==LOW){
    led1State=HIGH;
    led2State=LOW;
  }
  else {
    led1State=LOW;
    led2State=HIGH;
  }
  
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
 }
 delay(1);
  
}
