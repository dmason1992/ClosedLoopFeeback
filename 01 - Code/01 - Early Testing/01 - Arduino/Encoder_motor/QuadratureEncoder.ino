long pos = 0;

int phaseApin = 5;
int phaseBpin = 6;

int phaseAprev = 0;
int phaseAcurr = 0;
int phaseBprev = 0;
int phaseBcurr = 0;

void initialiseEncoders(){
  pinMode(phaseApin,INPUT_PULLUP);
  pinMode(phaseBpin,INPUT_PULLUP);

  phaseAcurr = digitalRead(phaseApin);
  phaseBcurr = digitalRead(phaseBpin);

  attachInterrupt(digitalPinToInterrupt(phaseApin), phaseAISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(phaseBpin), phaseBISR, CHANGE);
}

void phaseAISR(){
  phaseAprev = phaseAcurr;
  phaseAcurr = digitalRead(phaseApin);
  phaseBprev = phaseBcurr;
  updatePos();
  Serial.print("A:");
  Serial.print(phaseAcurr);
  Serial.print(" B:");
  Serial.println(phaseBcurr);
}

void phaseBISR(){
  phaseBprev = phaseBcurr;
  phaseBcurr = digitalRead(phaseBpin);
  phaseAprev = phaseAcurr;
  updatePos();
  Serial.print("A:");
  Serial.print(phaseAcurr);
  Serial.print(" B:");
  Serial.println(phaseBcurr);
}

void updatePos(){
  if (phaseAprev == 0 & phaseBprev == 1& phaseAcurr == 0 & phaseBcurr == 0){
    pos++;
  }
  else if (phaseAprev == 0 & phaseBprev == 0 & phaseAcurr == 1 & phaseBcurr == 0){
    pos++;
  }
  else if (phaseAprev == 1 & phaseBprev == 0 & phaseAcurr == 1 & phaseBcurr == 1){
    pos++;
  }
  else if (phaseAprev == 1 & phaseBprev == 1 & phaseAcurr == 0 & phaseBcurr == 1){
    pos++;
  }
  else if (phaseAprev == 0 & phaseBprev == 0 & phaseAcurr == 0 & phaseBcurr == 1){
    pos--;
  }
  else if (phaseAprev == 0 & phaseBprev == 1 & phaseAcurr == 1 & phaseBcurr == 1){
    pos--;
  }
  else if (phaseAprev == 1 & phaseBprev == 1 & phaseAcurr == 1 & phaseBcurr == 0){
    pos--;
  }
  else if (phaseAprev == 1 & phaseBprev == 0 & phaseAcurr == 0 & phaseBcurr == 0){
    pos--;
  }
}

float getDeg(){
  return pos * ( 360.0 / 2400.0 );
}

long getPos(){
  return pos;
}



