#include <Servo.h>

int servoPin = 9;
Servo servo;
int i = 0;
int switchpin = 8;
void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  servo.write(65);
  delay(1500);
  servo.write(30);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:



if(digitalRead(switchpin) == 1){
servo.write(65);
delay(1000);
}
}
