#define button 9;
int count=0;
int current, previous;

void setup() {
  pinMode(button, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("Edge Way");
  previous=HIGH;

}

void loop() {
  current=digitalRead(button);
  if(current==LOW && previous==HIGH) {
    count++;
  }
  delay(25);
  previous=current;
}
