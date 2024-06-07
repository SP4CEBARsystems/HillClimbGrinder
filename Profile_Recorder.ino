


void ProfileRecorder () {
  FancyLight(5);
  ButtonRead();
  switch (Button) {
    //Right and Left
    case 4:
      if (Stepper1Max == 0 && Stepper2Max == 0) {
        movement(6);
        Stepper1Max = 1;
        Stepper2Max = 1;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(6);");
      }
      if (Stepper1Max == 0) {
        movement(4);
        Stepper1Max = 1;

        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(4);");
      }
      if (Stepper2Max == 0) {
        movement(2);
        Stepper2Max = 1;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(2);");
      }
      break;
    //Left
    case 1:
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        movement(1);
        Stepper2Max = 0;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(1);");
      }
      if (Stepper1Max == 0) {
        movement(4);
        Stepper1Max = 1;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(4);");
      }
      break;
    //Right
    case 3:
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        movement(3);
        Stepper1Max = 0;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(3);");
      }
      if (Stepper2Max == 0) {
        movement(2);
        Stepper2Max = 1;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(2);");
      }
      break;
         
    //Mode
    case 2:
      endProfileRecMode = 1;
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 255);
      break;
    case 0:
      if (endProfileRecMode == 1) {
        ProfileRecorderMode = 0;
        endProfileRecMode = 0;
        Rotation = 8;
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
      }

      if (Stepper1Max == 1 && Stepper2Max == 1) {
        movement(5);
        Stepper1Max = 0;
        Stepper2Max = 0;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(5);");
      }
      if (Stepper1Max == 1) {
        movement(3);
        Stepper1Max = 0;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(3);");
      }
      if (Stepper2Max == 1) {
        movement(1);
        Stepper2Max = 0;
        
        Serial.print("delay(");
        Serial.print(DelayRecording*100);
        Serial.println(");");
        DelayRecording = 0;
        Serial.println("movement(1);");
      }
      break;
  }
  DelayRecording++;
}
