//========================= STEPPER CONTROLLER =========================
//  Contents:
//   - tap
//   - actual movement
//===================================================================

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//----------TAP----------

void tap(int tapOperation){
  switch (tapOperation) {
    case 0:
    break;
    case 1:
      movement (1);
      movement (2);
    break;
    case 2:
      movement (2);
      movement (1);
    break;
    case 3:
      movement (3);
      movement (4);
    break;
    case 4:
      movement (4);
      movement (3);
    break;
    case 5:
      movement (5);
      movement (6);
    break;
    case 6:
      movement (6);
      movement (5);
    break;
    case 7:
      movement (7);
      movement (8);
    break;
    case 8:
      movement (8);
      movement (7);
    break;
  }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//---------- ACTUAL MOVEMENT CONTROLLER ----------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void movement(int Operation) {
  CurrentStep = 0;

  while (CurrentStep < Rotation) {
           //freeze
      if (Operation == 0) {
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);

          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
      }

           //stepper 1 
      if (Operation == 1 || Operation == 2) {
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
          
        switch(StepNumber1){
          case 0:
          digitalWrite(STEPPER1_PIN_1, HIGH);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 1:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, HIGH);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 2:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, HIGH);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 3:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, HIGH);
          break;
        }
      }

           //stepper 2
      if (Operation == 3 || Operation == 4) {
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);
          
        switch(StepNumber2){
          case 0:
          digitalWrite(STEPPER2_PIN_1, HIGH);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 1:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, HIGH);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 2:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, HIGH);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 3:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, HIGH);
          break;
        } 
      }

           //stepper 1 and 2
      if (Operation == 5 || Operation == 6 || Operation == 7 || Operation == 8) {
        switch(StepNumber1){
          case 0:
          digitalWrite(STEPPER1_PIN_1, HIGH);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 1:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, HIGH);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 2:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, HIGH);
          digitalWrite(STEPPER1_PIN_4, LOW);
          break;
          case 3:
          digitalWrite(STEPPER1_PIN_1, LOW);
          digitalWrite(STEPPER1_PIN_2, LOW);
          digitalWrite(STEPPER1_PIN_3, LOW);
          digitalWrite(STEPPER1_PIN_4, HIGH);
          break;
        }

        switch(StepNumber2){
          case 0:
          digitalWrite(STEPPER2_PIN_1, HIGH);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 1:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, HIGH);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 2:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, HIGH);
          digitalWrite(STEPPER2_PIN_4, LOW);
          break;
          case 3:
          digitalWrite(STEPPER2_PIN_1, LOW);
          digitalWrite(STEPPER2_PIN_2, LOW);
          digitalWrite(STEPPER2_PIN_3, LOW);
          digitalWrite(STEPPER2_PIN_4, HIGH);
          break;
        }
    }
  
    
    if (Operation == 1 || Operation == 5 || Operation == 7) {
      if (SwitchState == true) {
        RelativePosition1++;
        if(RelativePosition1 > 1024){
          RelativePosition1 = -1023;
        }
      }
      StepNumber1++;
      if(StepNumber1 > 3){
        StepNumber1 = 0;
      }
    }

      if (Operation == 2 || Operation == 6 || Operation == 8) {
        if (SwitchState == true) {
          RelativePosition1--;
          if(RelativePosition1 < -1023){
            RelativePosition1 = 1024;
          }
        }
      StepNumber1--;
      if(StepNumber1 < 0){
        StepNumber1 = 3;
        }
      }
        
      if (Operation == 3 || Operation == 5 || Operation == 8) {
        if (SwitchState == true) {
          RelativePosition2++;
          if(RelativePosition2 > 1024){
            RelativePosition2 = -1023;
          }
        }
      StepNumber2++;
      if(StepNumber2 > 3){
        StepNumber2 = 0;
        }
      }

      if (Operation == 4 || Operation == 6 || Operation == 7) {
        if (SwitchState == true) {
          RelativePosition2--;
          if(RelativePosition2 < -1023){
            RelativePosition2 = 1024;
          }
        }
      StepNumber2--;
      if(StepNumber2 < 0){
        StepNumber2 = 3;
        }
      }

    if (SwitchState == false && ProfileRecorderMode == 0) {
      delay(Delay);
    }
    
    CurrentStep++;
    delay(3);
  }
  
  digitalWrite(STEPPER1_PIN_1, LOW);
  digitalWrite(STEPPER1_PIN_2, LOW);
  digitalWrite(STEPPER1_PIN_3, LOW);
  digitalWrite(STEPPER1_PIN_4, LOW);

  digitalWrite(STEPPER2_PIN_1, LOW);
  digitalWrite(STEPPER2_PIN_2, LOW);
  digitalWrite(STEPPER2_PIN_3, LOW);
  digitalWrite(STEPPER2_PIN_4, LOW);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
