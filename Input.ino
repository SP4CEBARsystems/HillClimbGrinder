//========================= USER INPUT AND OUTPUT =========================
//  Contents:
//   - Serial Communication
//   - User Input
//=========================================================================




//----------BUTTONS---------- (Figures out what buttons are pressed (3 buttons are connected to one analog pin))


void ButtonRead () {
  ButtonVal = analogRead(ReadButtons);
  //Serial.println(ButtonVal);
  //No button pressed
  if (ButtonVal < 100) {
    Button = 0;
  }
  //Button 1 Left  (Analog values: 509, 510)   (Previously: 974, 975, 976)    now: 504,505
  if (ButtonVal >= 450 && ButtonVal < 550) {
    Button = 1;
  }
  //Button 2 Mode  (Analog values: 840, 841)    now: around 826  
  if (ButtonVal >= 800 && ButtonVal < 900) {
    Button = 2;
  }
  //Button 3 Right  (Analog values: 656,657)   (Previously: 930, 931, 932)    now: 648
  if (ButtonVal >= 600 && ButtonVal < 700) {
    Button = 3;
  }
  //Button 4 Left and Right  (Analog values:  (around 753)   Previously: (867 868, or around 854)   (before Previously: 990, 991, 992))
  if (ButtonVal >= 700 && ButtonVal < 800) {
    Button = 4;
  }
}


//the function which interrupts any automation when the mode button is pressed

bool interruptAutomation() {
  ButtonVal = analogRead(ReadButtons);
  Serial.println(ButtonVal);
  //Serial.println(ButtonVal);
  if (ButtonVal >= 800 && ButtonVal < 900) {
    SwitchState = false;
    return true;
  } else {
    return false;
  }
}


//Interrupt automation for fast loops (doesn't activate due to noise)

bool interruptAutomationF() {
  ButtonVal = analogRead(ReadButtons);
  //Serial.println(ButtonVal);
  
  if (ButtonVal >= 800 && ButtonVal < 900) {
    if (InterruptTime > 10) {
      InterruptTime = 0;
      SwitchState = false;
      return true;
    } else {
      InterruptTime++;
      return false;
    }
  } else {
    InterruptTime = 0;
    return false;
  }
}

void userInput() {
  
  //----------BUTTONS---------- (controls the stepper set-up)
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

  //Button 2 Mode  (selects profiles, enters recorder mode, returns 50 steps, or switches stepper depending on press duration)
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
    if (B3PressDuration > 299 && B3PressDuration < 450) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 0);
      analogWrite(BlueLight, 255);
    }
    if (B3PressDuration > 449) {
      analogWrite(RedLight, 0);
      analogWrite(GreenLight, 255);
      analogWrite(BlueLight, 0);
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
    }
    //enter record profile mode
    if (B3PressDuration > 299 && B3PressDuration < 450) {
      ProfileRecorderMode = 1;
      Rotation = MaxRotation;
      RecorderStartTime = micros();
    }
    if (B3PressDuration > 449) {
      SwitchState = true;
      //Serial.println("WRITE");
    }
    B3PressDuration = 0;
  }
 




//----------POTENTIOMETERS----------
/*  MARKER 1
  Serial.print(analogRead(Profile));
  Serial.print("  ");
  Serial.println(analogRead(Speed));
*/

//----------Profile Potentiometer---------- (selects profile)
  if (ProfilePot != int(analogRead(Profile)/102.4) && abs(analogRead(Profile) - RawProfilePot) > 64) {  //noise barrier
    RawProfilePot = analogRead(Profile);
    ProfilePot = int(RawProfilePot/102.4);
    Pot1Changed = 1;
    Pot2Changed = 0;
    ConstantPot1Duration = 0;
    ConstantPot2Duration = 0;
    Serial.println(ProfilePot);

    switch(ProfilePot) {
      case 1:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        TProfileNo = 0;
        break;
      case 2:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        TProfileNo = 1;
        break;
      case 3:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 0);
        TProfileNo = 2;
        break;
      case 4:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 0);
        TProfileNo = 3;
        break;
      case 5:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 255);
        TProfileNo = 4;
        break;
      case 6:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 255);
        TProfileNo = 5;
        break;
      case 7:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 255);
        TProfileNo = 6;
        break;
      case 8:
        analogWrite(RedLight, 255);
        analogWrite(GreenLight, 255);
        analogWrite(BlueLight, 255);
        TProfileNo = 7;
        break;
      case 0:
        analogWrite(RedLight, 127);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
        LightColor = 1;
      case 9:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 127);
        break;
        LightColor = 6;
      }
      ProfileNo = 8*Menu + TProfileNo;
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

        //Previous Menu
        if (ProfilePot == 0) {
          LightColor = 1;
          Menu--;
          if (Menu < 0) {
            Menu = 3;
          }
          delay(10);
          pulseNtimes(Menu, LightColor);
        }
        //Next Menu
        if (ProfilePot == 9) {
          LightColor = 5;
          Menu++;
          if (Menu > 3) {
            Menu = 0;
          }
          delay(10);
          pulseNtimes(Menu, LightColor);
        }
        //Serial.println(Menu);
      }
      //Serial.println(ConstantPot1Duration);
    }
  }
   
//----------Stepper Speed Potentiometer---------- (Sets the speed of the stepper in the setup menu)
  if (SpeedPot != int(analogRead(Speed) / 400) && (ConstantPot1Duration == 0 || ConstantPot1Duration > 150) && abs(analogRead(Speed) - RawSpeedPot) > 64) { //Pin has a ton of noise -> Mega Noise barrier, true if Pot has changed.  Bug-Memorial: it was quoted out -> {
    RawSpeedPot = analogRead(Speed);
    SpeedPot = int(RawSpeedPot / 400);
    int SpeedPot2 = int(RawSpeedPot / 32);
    Delay = pow(2,map(SpeedPot2,0,31,-7,7));
    Pot2Changed = 1;
    Pot1Changed = 0;
    ConstantPot2Duration = 0;
    ConstantPot1Duration = 0;
    //-((Delay+1)*8-1)+255
    analogWrite(RedLight, pow(2,map(SpeedPot2,0,31,8,0)) - 1);
    analogWrite(GreenLight, 0);
    analogWrite(BlueLight, 0);
  }
  else {
    if (Pot2Changed == 1) {
      ConstantPot2Duration++;
      
      if (ConstantPot2Duration > 300) {
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        ConstantPot2Duration = 0;
        Pot2Changed = 0;
      }
    }
  }
}





//-------------SERIAL COMMUNICATION------------- (disabled) (used to control the steppers via a connected computer)
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
