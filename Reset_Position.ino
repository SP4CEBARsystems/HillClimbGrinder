//========================= RESET STEPPER POSITION =========================

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



void reset() {
  
  while(RelativePosition1 > 0){
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
    StepNumber1--;
    if(StepNumber1 < 0){
      StepNumber1 = 3;
    }
    RelativePosition1--;
    delay(3);
  }



  while(RelativePosition1 < 0){
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
    StepNumber1++;
    if(StepNumber1 > 3){
      StepNumber1 = 0;
    }
    RelativePosition1++;
    delay(3);
  }


  digitalWrite(STEPPER1_PIN_1, LOW);
  digitalWrite(STEPPER1_PIN_2, LOW);
  digitalWrite(STEPPER1_PIN_3, LOW);
  digitalWrite(STEPPER1_PIN_4, LOW);




  while(RelativePosition2 > 0){
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
    StepNumber2--;
    if(StepNumber2 < 0){
      StepNumber2 = 3;
    }
    RelativePosition2--;
    delay(3);
  }



  while(RelativePosition2 < 0){
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
    StepNumber2++;
    if(StepNumber2 > 3){
      StepNumber2 = 0;
    }
    RelativePosition2++;
    delay(3);
  }


  digitalWrite(STEPPER2_PIN_1, LOW);
  digitalWrite(STEPPER2_PIN_2, LOW);
  digitalWrite(STEPPER2_PIN_3, LOW);
  digitalWrite(STEPPER2_PIN_4, LOW);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
