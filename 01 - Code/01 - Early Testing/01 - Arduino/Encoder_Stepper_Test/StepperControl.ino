
/* ------------------------------------------------------------------------------------- \\  
 *                                        Notes
\\ ------------------------------------------------------------------------------------- */
/*
 * Steps per mm = 200;
 * 
 */

int enablePin = 5;
int dirPin = 7;
int stepperPin = 6;
float stepperPos = 0.0;
int microStepping = 16;
int stepsPerRev = 200*microStepping;
int rpm = 500;

void initialiseStepper(){
 pinMode(enablePin, OUTPUT);
 pinMode(dirPin, OUTPUT);  
 pinMode(stepperPin, OUTPUT);  
}

void enableStepper(boolean state){
  if (state){
    digitalWrite(enablePin, LOW); // logic is reversed on chip low is enabed
  }
  else {
    digitalWrite(enablePin, HIGH); // logic is reverse on chip high is disabled
  }
}

void step(boolean dir,float deg){
 long steps = abs(deg)*(stepsPerRev/360.0);
 long stepDelay = 1000000/((rpm / 60)*stepsPerRev);
 digitalWrite(dirPin,dir);
 delay(5);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delayMicroseconds(stepDelay);
   digitalWrite(stepperPin, LOW);
   delayMicroseconds(stepDelay);
 }

}

void abs_pos(float deg){
  float current_pos = E1_getDeg();
  if (deg > current_pos){
    step(false, deg-current_pos);
  }
  else if (deg < current_pos){
    step(true, current_pos-deg);
  }
  current_pos = E1_getDeg();
  if (abs(current_pos - deg) > 0.2){
    Serial.print("Error: ");
    Serial.println(current_pos-deg);
    abs_pos(deg);
  }
  else {
    Serial.print("Encoder: ");
    Serial.println(E1_getDeg()); 
  }

}

