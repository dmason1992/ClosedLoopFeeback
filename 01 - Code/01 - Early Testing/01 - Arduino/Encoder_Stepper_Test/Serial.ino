
void serialHandler(){ 
  if (Serial.available()){
    String Command = Serial.readString();

    if (Command == "Enable"){
      enableStepper(true);
      Serial.println("Stepper Enabled");
    }
    else if (Command == "Disable"){
      enableStepper(false);
      Serial.println("Stepper disabled");
    }
    else if (Command == "Zero"){
      zero();
      Serial.println("Encoder zeroed");
    }
    else if (Command == "Pos"){
      Serial.print("Pos: ");
      Serial.println(E1_getDeg());
    }
    else {
      int inDeg = Command.toInt();
      if (inDeg != 0){
        Serial.print("Stepping to: ");
        Serial.println(inDeg);
        abs_pos(inDeg);
      }
    }
  }
}
