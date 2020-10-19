#include <Servo.h>

#define SERVO_PIN 9
Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
}

void loop() {
  for(int i=0; i<=180; i++) {
    myservo.write(i);
    delay(15);
  }
  delay(1000);
    for(int i=180; i>=0; i--) {
    myservo.write(i);
    delay(15);
  }
  delay(2000);
}
