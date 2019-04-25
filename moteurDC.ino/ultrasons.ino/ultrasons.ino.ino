int trigPin = 9;
int echoPin = 10;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
int sensorValue = analogRead(A0);

long duration = pulseIn(echoPin,HIGH);

int distance = duration*0.343/20;

Serial.println(distance);
Serial.println(sensorValue);
delay(1000);
}
