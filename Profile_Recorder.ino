//========================= PROFILE RECORDER =========================

void ProfileRecorder () {
  if (millis() - StartFL >= 1) {     //Activate Fancy Light
    FancyLight(5);
    StartFL = millis();
  }
  
  ButtonRead();
  switch (Button) {

    //Right and Left
    case 4:
      if (Stepper1Max == 0 && Stepper2Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(6);  //both on
        Stepper1Max = 1;
        Stepper2Max = 1;
        Print(TimeStamp,6);
      }
      if (Stepper1Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(4);  //left on
        Stepper1Max = 1;
        Print(TimeStamp,4);
      }
      if (Stepper2Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(2);  //right on
        Stepper2Max = 1;
        Print(TimeStamp,2);
      }
      break;

      
    //Left
    case 1:
      if (Stepper1Max == 0 && Stepper2Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(7);  //left on and right off
        Stepper1Max = 1;
        Stepper2Max = 0;
        Print(TimeStamp,7);
      }
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(1);  //right off
        Stepper2Max = 0;
        Print(TimeStamp,1);
      }
      if (Stepper1Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(4);  //left on
        Stepper1Max = 1;
        Print(TimeStamp,4);
      }
      break;

      
    //Right (Stepper 2)
    case 3:
      if (Stepper1Max == 1 && Stepper2Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(8);  //right on and left off
        Stepper1Max = 0;
        Stepper2Max = 1;
        Print(TimeStamp,8);
      }
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(3);  //left off
        Stepper1Max = 0;
        Print(TimeStamp,3);
      }
      if (Stepper2Max == 0) {
        TimeStamp = micros() - RecorderStartTime;
        movement(2);  //right on
        Stepper2Max = 1;
        Print(TimeStamp,2);
      }
      break;

      
    //Idle
    case 0:
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(5);  //both off
        Stepper1Max = 0;
        Stepper2Max = 0;
        Print(TimeStamp,5);
      }
      if (Stepper1Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(3);  //left off
        Stepper1Max = 0;
        Print(TimeStamp,3);
      }
      if (Stepper2Max == 1) {
        TimeStamp = micros() - RecorderStartTime;
        movement(1);  //right off
        Stepper2Max = 0;
        Print(TimeStamp,1);
      }


      if (endProfileRecMode == 1) {
        ProfileRecorderMode = 0;
        endProfileRecMode = 0;
        Rotation = 8;
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
      }
    break;

    
    //Mode
    case 2:
      endProfileRecMode = 1;
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 255);
    break;
  }
}



void Print(long Time, int MovementType) {  //Bug-Memorial forgot to update this int to a long
  Serial.print("      StartAt(");
  Serial.print(Time);
  Serial.println(");");
  
  Serial.print("      movement(");
  Serial.print(MovementType);
  Serial.println(");");
  
  Serial.println("      if (interruptAutomation() == true) {break;}");
}
