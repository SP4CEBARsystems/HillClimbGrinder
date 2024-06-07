//========================= User Input and Output =========================
//  Contents:
//   - Serial Communication
//   - User Input
//=========================================================================




//-------------SERIAL COMMUNICATION-------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void serialCommunication() {
  //BUG: if the statement must have activated every time...   it seems to be purposed to work this way    previously it was no problem because the operation variable stayed the same
  if (Serial.available() > 0) {
  receivedChar = Serial.read();
  Serial.println(receivedChar);
  }

  if (receivedChar == 0) {

  }
  if (receivedChar == ' ') {
    movement(0);
  }
  if (receivedChar == 'q') {
    movement(1);
  }
  if (receivedChar == 'a') {
    movement(2);
  }
  if (receivedChar == 'w') {
    movement(3);
  }
  if (receivedChar == 's') {
    movement(4);
  }
  if (receivedChar == 'e') {
    movement(5);
  }
  if (receivedChar == 'd') {
    movement(6);
  }
  if (receivedChar == 'r') {
    Delay++;
    Serial.print(Delay);
  }
  if (receivedChar == 'f') {
    Delay--;
    Serial.print(Delay);
  }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//----------BUTTONS----------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void userInput() {
//----------BUTTONS----------
  ButtonRead ();

  //Button 1 Left 
  if (Button == 1) {
    //Serial.println("Left");
    if (editStepperPos == 0) {
      movement(2);
    }
    if (editStepperPos == 1) {
      movement(3);
    }
  } 

  //Button 3 Right 
  if (Button == 3) {
    //Serial.println("Right");
    if (editStepperPos == 0) {
      movement(1);
    }
    if (editStepperPos == 1) {
      movement(4);
    }
  }

  //Button 2 Mode
  if (Button == 2) {
    //Serial.println("Mode");
    B3PressDuration++;
    //Serial.println(B3PressDuration);
    if (B3PressDuration > 10 && B3PressDuration < 150) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 63);
    }
    if (B3PressDuration > 149 && B3PressDuration < 300) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 127);
    }
    if (B3PressDuration > 299) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 255);
    }
  }
  else {
    //Serial.println(B3PressDuration);
    //delay (2000);
    if (B3PressDuration > 10) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 0);
    }
    
    //Switch Stepper
    if (B3PressDuration > 10 && B3PressDuration < 150) {
      editStepperPos = !editStepperPos;
    }
    //return both steppers 1x MaxRotation (150 steps)
    if (B3PressDuration > 149 && B3PressDuration < 300) {
      Rotation = MaxRotation;
      movement(5);
      Rotation = 8;
    //enter record profile mode
    }
    if (B3PressDuration > 299) {
      ProfileRecorderMode = 1;
      Rotation = MaxRotation;
    }
    B3PressDuration = 0;
  }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




//----------POTENTIOMETERS----------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//----------Profile Potentiometer----------
  if (ProfilePot != analogRead(Profile)/128) {
    ProfilePot = analogRead(Profile)/128;
    Pot1Changed = 1;
    ConstantPot1Duration = 0;
    //Serial.println(ProfilePot);

    switch(ProfilePot) {
      case 0:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 1:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 2:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 0);
        break;
      case 3:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 0);
        break;
      case 4:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 255);
        break;
      case 5:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 255);
        break;
      case 6:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 255);
        break;
      case 7:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 255);
        break;
      }
  }
  else {
    if (Pot1Changed == 1) {
    ConstantPot1Duration++;
      
      if (ConstantPot1Duration > 300) {
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        ConstantPot1Duration = 0;
        Pot1Changed = 0;
      }
    } 
  } 
   
//----------Stepper Speed Potentiometer----------
  if (Delay != analogRead(Speed)/32) {
    Delay = analogRead(Speed)/32;
    Pot2Changed = 1;
    //Serial.println(Delay);
    //-((Delay+1)*8-1)+255
    analogWrite(RedLight, map(Delay,0,31,255,7));
    analogWrite(GreenLight, 0);
    analogWrite(BlueLight, 0);
  }
  else {
    if (Pot2Changed == 1) {
      ConstantPot2Duration++;
      
      if (ConstantPot2Duration > 500) {
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        ConstantPot2Duration = 0;
        Pot2Changed = 0;
      }
    }
  }
//Stepper Distance Potentiometer is included in the profile function

}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void ButtonRead () {
  ButtonVal = analogRead(ReadButtons);
  //Serial.println(ButtonVal);
  //No button pressed
  if (ButtonVal < 100) {
    Button = 0;
  }
  //Button 1 Left  (Analog values: 509, 510)   (Previously: 974, 975, 976)
  if (ButtonVal > 450 && ButtonVal < 550) {
    Button = 1;
  }
  //Button 2 Mode  (Analog values: 656,657)   (Previously: 930, 931, 932)
  if (ButtonVal > 600 && ButtonVal < 700) {
    Button = 2;
  }
  //Button 3 Right  (Analog values: 840, 841)
  if (ButtonVal > 800 && ButtonVal < 860) {
    Button = 3;
  }
  //Button 4 Left and Right  (Analog values: 867 868)   (Previously: 990, 991, 992)
  if (ButtonVal > 859 && ButtonVal < 900) {
    Button = 4;
  }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
