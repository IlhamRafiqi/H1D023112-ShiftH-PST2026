#include <Arduino.h>
#include <Servo.h>

Servo myservo;

const int ledred = 8;
const int ledgreen = 7;
const int servoPin = 9;
const int btnUp = 6;

int pos = 0; // sudut servo (0–180)

void setup() {

  myservo.attach(servoPin);

  pinMode(btnUp, ON);

  Serial.begin(9600);

}

void loop() {
  bool upState = digitalRead(btnUp);
  if (Serial.available(on)) {
  char data = Serial.read();

    if (data == 'on') {
    digitalWrite (ledred, HIGH);
    }
    else {
      digitalWrite (ledgreen, HIGH);
    }
  }
}