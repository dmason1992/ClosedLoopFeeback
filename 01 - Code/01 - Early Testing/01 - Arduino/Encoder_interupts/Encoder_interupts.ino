long oldPos = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initialiseEncoders();

}



void loop() {
  if (getPos() != oldPos){
    oldPos = getPos();
    Serial.println(getDeg());
  }
}
