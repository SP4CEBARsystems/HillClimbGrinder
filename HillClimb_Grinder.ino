//HillClimb Grinder
//Automate mobile games

//created by SP4CEBAR - sp4cebar.com
//based on code Written By Nikodem Bartnik - nikodembartnik.pl

//-----------------------------------------------------------------------



//-------------set up-------------
#define STEPPER1_PIN_1 8
#define STEPPER1_PIN_2 7
#define STEPPER1_PIN_3 6
#define STEPPER1_PIN_4 5

#define STEPPER2_PIN_1 12
#define STEPPER2_PIN_2 11
#define STEPPER2_PIN_3 10
#define STEPPER2_PIN_4 9

#define PowerSwitch 13

int CurrentStep = 0;
int StepNumber1 = 0;
int StepNumber2 = 0;
int RelativePosition1 = 0;
int RelativePosition2 = 0;
int MaxRotation = 150;
int Rotation = MaxRotation;
int Delay = 0;
int DelayPart = 0;
char receivedChar;
bool SwitchState = digitalRead(PowerSwitch);


void setup() {
pinMode(STEPPER1_PIN_1, OUTPUT);
pinMode(STEPPER1_PIN_2, OUTPUT);
pinMode(STEPPER1_PIN_3, OUTPUT);
pinMode(STEPPER1_PIN_4, OUTPUT);

pinMode(STEPPER2_PIN_1, OUTPUT);
pinMode(STEPPER2_PIN_2, OUTPUT);
pinMode(STEPPER2_PIN_3, OUTPUT);
pinMode(STEPPER2_PIN_4, OUTPUT);

pinMode(PowerSwitch, INPUT);

Serial.begin(9600);
Serial.println("<Arduino is ready>");

//movement (5);
//movement (6);
}






//-------------main loop-------------

void loop() {

//--------Switch OFF--------
  if(SwitchState == false) {
    Rotation = 20;
  }
  
  while(SwitchState == false) {
    recvOneChar();
    process();
    SwitchState = digitalRead(PowerSwitch);
  }


//--------Switch ON--------
  if(SwitchState == true) {
    Rotation = MaxRotation;
  }
  
  while(SwitchState == true) {
  tap(2);
    delay(400);
  movement(6);
    //total delay = 5,180 ms
    ActiveDelay(5000);
    if(SwitchState == false) {break;}
    delay(180);
  movement(3);
    delay(500);
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {break;}
  movement(1);
  movement(4);
    delay(500);
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {break;}
  movement(3);
  movement(2);
    delay(500);
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {break;}
  movement(1);
  //total delay = 20,000 ms
    ActiveDelay(20000);
    if(SwitchState == false) {break;}
  tap(2);
    SwitchState = digitalRead(PowerSwitch);
  }
  reset();
}




void ActiveDelay(int MaxDelay) {
  MaxDelay = MaxDelay / 500;
  while (DelayPart < MaxDelay) {
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {break;}
    DelayPart++;
    delay(500);
  }
  DelayPart = 0;
}




//-------------serial communication-------------


void recvOneChar() {
  //BUG: if the statement must have activated every time...   it seems to be purposed to work this way    previously it was no problem because the operation variable stayed the same
  if (Serial.available() > 0) {
  receivedChar = Serial.read();
  Serial.println(receivedChar);
  }
}



void process() {
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





//-------------stepper control-------------


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

//-----------Actual Movement Controller-----------

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

    if (SwitchState == false) {delay(Delay);}
    
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



//------------------RESET------------------

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
