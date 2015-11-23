long E1_pos = 0;

int E1_phaseApin = A9;
int E1_phaseBpin = A10;

int E1_phaseAprev = 0;
int E1_phaseAcurr = 0;
int E1_phaseBprev = 0;
int E1_phaseBcurr = 0;


void initialiseEncoders(){
  // initialise encoder 1 pins
  pinMode(E1_phaseApin,INPUT_PULLUP);
  pinMode(E1_phaseBpin,INPUT_PULLUP);

  // get encoder 1 initial pin states
  E1_phaseAcurr = digitalRead(E1_phaseApin);
  E1_phaseBcurr = digitalRead(E1_phaseBpin);

  // attach interupts for encoder 1
  enableInterrupt(E1_phaseApin, E1_phaseAISR, CHANGE);
  enableInterrupt(E1_phaseBpin, E1_phaseBISR, CHANGE);
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

float E1_getDeg(){
  return E1_pos * ( 360.0 / 2400.0 );
}

long E1_getPos(){
  return E1_pos;
}

void zero(){
  E1_pos = 0;
}




