long E1_oldPos = 0;
long E2_oldPos = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initialiseEncoders();

}



void loop() {
  if ((E1_getPos() != E1_oldPos ) || (E2_getPos() != E2_oldPos)){
    E1_oldPos = E1_getPos();
    E2_oldPos = E2_getPos();
    Serial.print("E1:");
    Serial.print(E1_getDeg());
    Serial.print(" E2:");
    Serial.println(E2_getDeg());
  }
}
