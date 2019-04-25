int enablePin = 11;
int in1Pin1 = 7;
int in2Pin2 = 6;
int switchPin = 5;
int potPin = 0;




void setup() {
  // put your setup code here, to run once:
//pinMode(enablePin,INPUT);
pinMode(in1Pin1,OUTPUT);
pinMode(in2Pin2,OUTPUT);
pinMode(switchPin, INPUT_PULLUP);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1Pin1, HIGH);
digitalWrite(in2Pin2, HIGH);
int sensorValue = analogRead(A0)*5.0/1023;
Serial.println(sensorValue);
delay(1000);
Serial.println(in1Pin1);
digitalWrite(in1Pin1, LOW);
digitalWrite(in2Pin2, LOW);

delay(1000);


}
