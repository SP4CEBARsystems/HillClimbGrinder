//based on code Written By Nikodem Bartnik - nikodembartnik.pl
//edited by SP4CEBAR - sp4cebar.com
#define STEPPER1_PIN_1 5
#define STEPPER1_PIN_2 6
#define STEPPER1_PIN_3 7
#define STEPPER1_PIN_4 8

#define STEPPER2_PIN_1 9
#define STEPPER2_PIN_2 10
#define STEPPER2_PIN_3 11
#define STEPPER2_PIN_4 12

int CurrentStep = 0;
int StepNumber1 = 0;
int StepNumber2 = 0;
int MaxRotation = 150;

void setup() {
pinMode(STEPPER1_PIN_1, OUTPUT);
pinMode(STEPPER1_PIN_2, OUTPUT);
pinMode(STEPPER1_PIN_3, OUTPUT);
pinMode(STEPPER1_PIN_4, OUTPUT);

pinMode(STEPPER2_PIN_1, OUTPUT);
pinMode(STEPPER2_PIN_2, OUTPUT);
pinMode(STEPPER2_PIN_3, OUTPUT);
pinMode(STEPPER2_PIN_4, OUTPUT);

Serial.begin(9600);
//movement (5);
//movement (6);
}


void loop() {
  tap(2);
  delay(400);
  movement(6);
  delay(5180);
  movement(3);
  delay(500);
  movement(1);
  movement(4);
  delay(500);
  movement(3);
  movement(2);
  delay(500);
  movement(1);
  delay(20000);
  tap(2);
}



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



void movement(int Operation) {
  CurrentStep = 0;

  while (CurrentStep < MaxRotation) {
           //stepper 1 
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
    StepNumber1++;
      if(StepNumber1 > 3){
        StepNumber1 = 0;
     }
    }

    if (Operation == 2 || Operation == 6 || Operation == 8) {
    StepNumber1--;
      if(StepNumber1 < 0){
        StepNumber1 = 3;
      }
    }
        
    if (Operation == 3 || Operation == 5 || Operation == 8) {
    StepNumber2++;
      if(StepNumber2 > 3){
        StepNumber2 = 0;
      }
    }

    if (Operation == 4 || Operation == 6 || Operation == 7) {
    StepNumber2--;
      if(StepNumber2 < 0){
        StepNumber2 = 3;
      }
    }
      
    CurrentStep++;
    delay(3);
    delay(0);
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


//28720 loop
