int dirPin = 7;
int stepperPin = 6;
int enablePin = 5;
boolean isEnabled = false;

void setup() {
 Serial.begin(115200);
 pinMode(dirPin, OUTPUT);
 pinMode(stepperPin, OUTPUT);
 pinMode(13,OUTPUT);
}

void step(boolean dir,int steps){
 digitalWrite(dirPin,dir);
 delay(1);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delayMicroseconds(800);
   digitalWrite(stepperPin, LOW);
   delayMicroseconds(800);
 }
}

void serialHandler(){ 
  if (Serial.available()){
    while(Serial.available()){
      byte temp = Serial.read();
    }
    isEnabled = !isEnabled;
    if (isEnabled){
      digitalWrite(enablePin,HIGH);
    }
    else {
      digitalWrite(enablePin,LOW);
    }
  }
}

void loop(){

  // run serial handler
  serialHandler();

  // motor control
   step(true,1600);


}
