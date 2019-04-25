#include <Servo.h>

int potPin = 0;
int servoPin = 9;
Servo servo;

void setup() {
  // put your setup code here, to run once:
servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
int lecture = analogRead(potPin);
int angle = lecture/6;
servo.write(angle);
}
