//#include <Servo.h>
int motor1_enablePin = 11; //pwm
int motor1_in1Pin = 13;
int motor1_in2Pin = 12;

int trigPin = 9;//ultrason
int echoPin = 6;

//int servoPin = 5;//servoMoteur
//Servo servo;
//int angle = 0;
 
int motor2_enablePin = 10; //pwm
int motor2_in1Pin = 8;
int motor2_in2Pin = 7;
 
void setup()
{
  //on initialise les pins du moteur 1
  pinMode(motor1_in1Pin, OUTPUT);
  pinMode(motor1_in2Pin, OUTPUT);
  pinMode(motor1_enablePin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //servo.attach(servoPin);
  
  //on initialise les pins du moteur 2
  pinMode(motor2_in1Pin, OUTPUT);
  pinMode(motor2_in2Pin, OUTPUT);
  pinMode(motor2_enablePin, OUTPUT);
  Serial.begin(9600);//initialise le moniteur série
}
 
void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long duration = pulseIn(echoPin,HIGH);
  int distance = duration*0.343/20;
  float volts = analogRead(A2)*5.0/1023.0;
  int distance2 = 13*pow(volts,-1);
 
  //SetMotor2(175, true);
  //SetMotor1(255, false);
  int tracker1 = analogRead(A0)*5.0/1023;
  int tracker2 = analogRead(A1)*5.0/1023;
  analogWrite(motor1_enablePin, 200);//Je set le moteur 1, 255 = vitesse max on peut changer la vitesse si on veut
  analogWrite(motor2_enablePin, 200);//Je set le moteur 2, 255 = vitesse max
  digitalWrite(motor1_in1Pin, LOW);
  digitalWrite(motor1_in2Pin, HIGH);
  digitalWrite(motor2_in1Pin, HIGH);
  digitalWrite(motor2_in2Pin, LOW);
  
  /*Serial.println(tracker1);
  Serial.println(distance);
  Serial.println('-');
  Serial.println(distance2);
  

  servo.write(angle);
  delay(10);
  angle=angle++;
  */
  
  //quand y voit du noir y tourne,pour du blanc on remplace par 4
  if(tracker1==4){
  digitalWrite(motor1_in1Pin, LOW);
  digitalWrite(motor1_in2Pin, HIGH);
  digitalWrite(motor2_in1Pin, LOW);
  digitalWrite(motor2_in2Pin, HIGH);
  delay(750);
  digitalWrite(motor1_in1Pin, LOW);
  digitalWrite(motor1_in2Pin, HIGH);
  digitalWrite(motor2_in1Pin, HIGH);
  digitalWrite(motor2_in2Pin, LOW);
  delay(750);
  }
  // quand y voit du noir y tourne, pour du blanc on remplace par 4
  if(tracker2==4){
  digitalWrite(motor1_in1Pin, LOW);
  digitalWrite(motor1_in2Pin, HIGH);
  digitalWrite(motor2_in1Pin, LOW);
  digitalWrite(motor2_in2Pin, HIGH);
  delay(750);
  digitalWrite(motor1_in1Pin, LOW);
  digitalWrite(motor1_in2Pin, HIGH);
  digitalWrite(motor2_in1Pin, HIGH);
  digitalWrite(motor2_in2Pin, LOW);
  delay(750);
  }
 
  if(distance>=3 && distance<=25)//ultrason quier sul devant
  {
    analogWrite(motor1_enablePin, 255);
    analogWrite(motor2_enablePin, 255);
    digitalWrite(motor1_in1Pin, LOW);
    digitalWrite(motor1_in2Pin, HIGH);
    digitalWrite(motor2_in1Pin, HIGH);
    digitalWrite(motor2_in2Pin, LOW);
    
    
    delay(750);
    
  }
  
  if(distance2<=5)// infrarouge qui cheke le back
  {
    analogWrite(motor1_enablePin, 100);
    analogWrite(motor2_enablePin, 255);
    digitalWrite(motor1_in1Pin, LOW);
    digitalWrite(motor1_in2Pin, HIGH);
    digitalWrite(motor2_in1Pin, HIGH);
    digitalWrite(motor2_in2Pin, LOW);
    delay(1000);
  }




  
}
 


