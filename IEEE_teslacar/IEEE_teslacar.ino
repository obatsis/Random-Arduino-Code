#include <Servo.h>
#include "NewPing.h"

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
#define SERVO_PIN 9

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
int distance;
int angle;
int pot = A1;
int potValue;

void setup() {
    Serial.begin(9600);
    myservo.attach(SERVO_PIN);
    myservo.write(90);
}

void loop() {
    potValue=analogRead(pot);
    angle=map(potValue, 0, 1023, 0, 180);
    myservo.write(angle);
    Serial.print("Distance: ");
    Serial.println(distance);
    distance=sonar.ping_cm();
    if(distance<=15 && distance!=0) {
      manuvra();
    }
    delay(150);
    
}

void manuvra() {
  myservo.write(180);
  delay(500);
  distance=sonar.ping_cm();
  if(distance<=15 && distance!=0) {
    myservo.write(0);
    delay(500);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(500);
    myservo.write(90);
  }
  else{
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(500);
    myservo.write(90);
 }
}

