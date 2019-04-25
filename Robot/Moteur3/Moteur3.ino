
void setup() {
  // put your setup code here, to run once:
#include 

Motor motors[2] = { Motor(9, 2, 3), Motor(10, 4, 5) };

void setup()
{
    motors[0].init();
    motors[1].init();
}
}

void loop() {
  // put your main code here, to run repeatedly:
    motors[0].setSpeed(128);
    motors[1].setSpeed(-85);
}
