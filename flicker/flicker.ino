int ledPin=10;
byte flicker[]={10, 30, 60, 90, 150, 180, 200, 255};
//int potPin=0;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
 // int delayTimer=analogRead(potPin);
  for(int i=0; i<=5; i++) {
    analogWrite(ledPin, flicker[i]);
  //  delay(delayTimer);
      delay(100); 
  }
}

