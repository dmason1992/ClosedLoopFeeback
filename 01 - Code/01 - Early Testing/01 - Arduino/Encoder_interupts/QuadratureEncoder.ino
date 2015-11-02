long E1_pos = 0;
long E2_pos = 0;

int E1_phaseApin = 5;
int E1_phaseBpin = 6;
int E2_phaseApin = 7;
int E2_phaseBpin = 8;

int E1_phaseAprev = 0;
int E1_phaseAcurr = 0;
int E1_phaseBprev = 0;
int E1_phaseBcurr = 0;

int E2_phaseAprev = 0;
int E2_phaseAcurr = 0;
int E2_phaseBprev = 0;
int E2_phaseBcurr = 0;

void initialiseEncoders(){
  // initialise encoder 1 pins
  pinMode(E1_phaseApin,INPUT_PULLUP);
  pinMode(E1_phaseBpin,INPUT_PULLUP);
  
  // initialise encoder 2 pins
  pinMode(E2_phaseApin,INPUT_PULLUP);
  pinMode(E2_phaseBpin,INPUT_PULLUP);

  // get encoder 1 initial pin states
  E1_phaseAcurr = digitalRead(E1_phaseApin);
  E1_phaseBcurr = digitalRead(E1_phaseBpin);

  // get encoder 2 initial pin states
  E2_phaseAcurr = digitalRead(E2_phaseApin);
  E2_phaseBcurr = digitalRead(E2_phaseBpin);

  // attach interupts for encoder 1
  attachInterrupt(digitalPinToInterrupt(E1_phaseApin), E1_phaseAISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(E1_phaseBpin), E1_phaseBISR, CHANGE);

  // attach interupts for encoder 2
  attachInterrupt(digitalPinToInterrupt(E2_phaseApin), E2_phaseAISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(E2_phaseBpin), E2_phaseBISR, CHANGE);
}

void E1_phaseAISR(){
  E1_phaseAprev = E1_phaseAcurr;
  E1_phaseAcurr = digitalRead(E1_phaseApin);
  E1_phaseBprev = E1_phaseBcurr;
  E1_updatePos();
}

void E1_phaseBISR(){
  E1_phaseBprev = E1_phaseBcurr;
  E1_phaseBcurr = digitalRead(E1_phaseBpin);
  E1_phaseAprev = E1_phaseAcurr;
  E1_updatePos();
}

void E2_phaseAISR(){
  E2_phaseAprev = E2_phaseAcurr;
  E2_phaseAcurr = digitalRead(E2_phaseApin);
  E2_phaseBprev = E2_phaseBcurr;
  E2_updatePos();
}

void E2_phaseBISR(){
  E2_phaseBprev = E2_phaseBcurr;
  E2_phaseBcurr = digitalRead(E2_phaseBpin);
  E2_phaseAprev = E2_phaseAcurr;
  E2_updatePos();
}

void E1_updatePos(){
  if (E1_phaseAprev == 0 & E1_phaseBprev == 1& E1_phaseAcurr == 0 & E1_phaseBcurr == 0){
    E1_pos++;
  }
  else if (E1_phaseAprev == 0 & E1_phaseBprev == 0 & E1_phaseAcurr == 1 & E1_phaseBcurr == 0){
    E1_pos++;
  }
  else if (E1_phaseAprev == 1 & E1_phaseBprev == 0 & E1_phaseAcurr == 1 & E1_phaseBcurr == 1){
    E1_pos++;
  }
  else if (E1_phaseAprev == 1 & E1_phaseBprev == 1 & E1_phaseAcurr == 0 & E1_phaseBcurr == 1){
    E1_pos++;
  }
  else if (E1_phaseAprev == 0 & E1_phaseBprev == 0 & E1_phaseAcurr == 0 & E1_phaseBcurr == 1){
    E1_pos--;
  }
  else if (E1_phaseAprev == 0 & E1_phaseBprev == 1 & E1_phaseAcurr == 1 & E1_phaseBcurr == 1){
    E1_pos--;
  }
  else if (E1_phaseAprev == 1 & E1_phaseBprev == 1 & E1_phaseAcurr == 1 & E1_phaseBcurr == 0){
    E1_pos--;
  }
  else if (E1_phaseAprev == 1 & E1_phaseBprev == 0 & E1_phaseAcurr == 0 & E1_phaseBcurr == 0){
    E1_pos--;
  }
}

void E2_updatePos(){
  if (E2_phaseAprev == 0 & E2_phaseBprev == 1& E2_phaseAcurr == 0 & E2_phaseBcurr == 0){
    E2_pos++;
  }
  else if (E2_phaseAprev == 0 & E2_phaseBprev == 0 & E2_phaseAcurr == 1 & E2_phaseBcurr == 0){
    E2_pos++;
  }
  else if (E2_phaseAprev == 1 & E2_phaseBprev == 0 & E2_phaseAcurr == 1 & E2_phaseBcurr == 1){
    E2_pos++;
  }
  else if (E2_phaseAprev == 1 & E2_phaseBprev == 1 & E2_phaseAcurr == 0 & E2_phaseBcurr == 1){
    E2_pos++;
  }
  else if (E2_phaseAprev == 0 & E2_phaseBprev == 0 & E2_phaseAcurr == 0 & E2_phaseBcurr == 1){
    E2_pos--;
  }
  else if (E2_phaseAprev == 0 & E2_phaseBprev == 1 & E2_phaseAcurr == 1 & E2_phaseBcurr == 1){
    E2_pos--;
  }
  else if (E2_phaseAprev == 1 & E2_phaseBprev == 1 & E2_phaseAcurr == 1 & E2_phaseBcurr == 0){
    E2_pos--;
  }
  else if (E2_phaseAprev == 1 & E2_phaseBprev == 0 & E2_phaseAcurr == 0 & E2_phaseBcurr == 0){
    E2_pos--;
  }
}

float E1_getDeg(){
  return E1_pos * ( 360.0 / 2400.0 );
}
float E2_getDeg(){
  return E2_pos * ( 360.0 / 2400.0 );
}

long E1_getPos(){
  return E1_pos;
}
long E2_getPos(){
  return E2_pos;
}



