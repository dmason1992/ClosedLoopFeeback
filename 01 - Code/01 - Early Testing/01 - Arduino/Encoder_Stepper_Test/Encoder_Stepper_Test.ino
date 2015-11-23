
/* ------------------------------------------------------------------------------------- \\  
 *                                        Wiring
\\ ------------------------------------------------------------------------------------- */
/*
 * Encoder -> Arduino
 * Power -> 5V
 * Gnd -> Gnd
 * Phase A -> A12 / A10 (Encoder 1 / Encoder 2)
 * Phase B -> A11 / A9 (Encoder 1 / Encoder 2)
 * 
 */

/* ------------------------------------------------------------------------------------- \\  
 *                             Functional Code Below This line
\\ ------------------------------------------------------------------------------------- */

#include <EnableInterrupt.h>

long E1_oldPos = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initialiseEncoders();
  initialiseStepper();

}



void loop() {
  serialHandler();

}
