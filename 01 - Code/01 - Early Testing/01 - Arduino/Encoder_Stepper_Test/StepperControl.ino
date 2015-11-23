
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
 int steps = abs(deg)*((200.0*16)/360.0);
 digitalWrite(dirPin,dir);
 delay(50);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(stepperPin, LOW);
   delayMicroseconds(200);
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
  if (abs(current_pos - deg) > 0.1){
    abs_pos(deg);
  }
  else {
    Serial.print("Encoder: ");
    Serial.println(E1_getDeg()); 
  }

}

