int led=9;
int ledState;
unsigned long previous, current;
long interval;

void setup() {
  pinMode(led, OUTPUT);
  interval=1000;
  previous=0;
  
}

void loop() {
 current=millis();
 if(current-previous > interval) {
  previous=current;
  if(ledState==LOW){
    ledState=HIGH;
  }
  else {
    ledState=LOW;
  }
  digitalWrite(led, ledState);
 }
}
