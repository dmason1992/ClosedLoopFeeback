int enablePin = 12;
int in1Pin = 11;
int in2Pin = 10;

boolean reverse = false;
 
void setup()
{
  Serial.begin(115200);
  initialiseEncoders();
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}
 
void loop()
{

  int speed = 1023;
  //reverse = !reverse;
  setMotor(speed, reverse);
}
 
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}
