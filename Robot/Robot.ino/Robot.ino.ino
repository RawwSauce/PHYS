#include <Servo.h>

int trigPin = 9;
int echoPin = 10;
int servoPin = 8;
Servo servo;
int angle = 0;

void setup() {

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
servo.attach(servoPin);
}
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
int sensorValue = analogRead(A0)*5.0/1023;
float volts = analogRead(A1)*5.0/1023.0;
int distance2 = 13*pow(volts,-1);


long duration = pulseIn(echoPin,HIGH);

int distance = duration*0.343/20;

for(angle = 0;angle < 180; angle++)
{
  servo.write(angle);
  delay(10);
  
}
for(angle = 180;angle > 0; angle--)
{
  servo.write(angle);
  delay(10);
}

Serial.println(distance);
Serial.println(distance2);
Serial.println(sensorValue);
Serial.println('-');

delay(100);
}
