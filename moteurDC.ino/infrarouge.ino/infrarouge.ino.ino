void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float volts = analogRead(A0)*5.0/1023;  
  int distance = 13*pow(volts,-1);
  Serial.println(distance);
  delay(100);

}
