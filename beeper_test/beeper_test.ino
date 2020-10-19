int beep=11;
int button=12;

void setup() {
  pinMode(button,INPUT_PULLUP);

}

void loop() {
  if(digitalRead(button)==LOW) {
    tone(beep, 3000, 100);
  }

}
