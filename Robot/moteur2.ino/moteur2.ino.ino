
int in1Pin1 = 7;
int in2Pin2 = 6;






void setup() {
  // put your setup code here, to run once:
//pinMode(enablePin,INPUT);
pinMode(in1Pin1,OUTPUT);
pinMode(in2Pin2,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1Pin1, HIGH);
digitalWrite(in2Pin2, HIGH);
int sensorValue1 = analogRead(A0)*5.0/1023;
int sensorValue2 = analogRead(A1)*5.0/1023;
Serial.println(sensorValue1);
if (sensorValue1==0 || sensorValue2==0 ){
  digitalWrite(in1Pin1, HIGH);
  digitalWrite(in2Pin2, HIGH);
  
}
if(sensorValue1==4){
  digitalWrite(in1Pin1, HIGH);
  digitalWrite(in2Pin2, LOW);
  delay(1500);
  digitalWrite(in1Pin1, HIGH);
  
}
if(sensorValue2==4){
  digitalWrite(in1Pin1, LOW);
  digitalWrite(in2Pin2, HIGH);
  delay(1500);
  digitalWrite(in1Pin1, HIGH);
  
}





}
