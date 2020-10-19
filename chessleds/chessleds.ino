int led1=12;
int led2=11;
int button=2;
int led1State;
int led2State;
unsigned long current, previous;
long interval;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  led1State=HIGH;
  led2State=LOW;
  digitalWrite(led1, led1State);
  previous=0;
  interval=5000;
}

void loop() {
 current=millis();
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
 if((digitalRead(button)==LOW) && current-previous > 500) {
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

}
