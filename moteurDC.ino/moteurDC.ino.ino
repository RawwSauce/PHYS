int enablePin=11;
int in1Pin=10;
int in2Pin=9;
int switchPin=7;
int potPin=0;

void setup() {
  // put your setup code here, to run once:
pinMode (enablePin, OUTPUT);
pinMode (in1Pin, OUTPUT);
pinMode (in2Pin, OUTPUT);
pinMode (switchPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
int vitesse = analogRead(potPin) / 4;
boolean changesens = digitalRead (switchPin);
setMoteur (vitesse, changesens);
}

void setMoteur (int vitesse, boolean changesens)
{
  analogWrite (enablePin, vitesse);
  digitalWrite (in1Pin, ! changesens);
  digitalWrite (in2Pin, changesens);
}

