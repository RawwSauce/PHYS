int switchpin1 = 10;
int servoPin = 9;
#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
servo.attach(servoPin);
}

void loop() {
  
  if(digitalRead(switchpin1 == 1){
    //ferme
    servo.write(75);
  }
  if(digitalRead(switchpin1) == 0){
    //ouvert
    servo.write(50);
  }

}
