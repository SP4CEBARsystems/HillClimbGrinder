//========================= MAIN LOOP =========================
//  Contents:
//   - void loop()
//   - Run Profile
//   - Active Delay
//=============================================================


//---------------------- LOOP --------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void loop() {
  //--------Switch OFF--------
  if(SwitchState == false) {
    Rotation = 8;
  }
  
  while(SwitchState == false) {
    //serialCommunication();
    if (ProfileRecorderMode == 0) {
      userInput();
    }
    else {
      ActiveDelay2(100);
      ProfileRecorder();
    }
    //FancyLight(5);
    delay(2);
    SwitchState = digitalRead(PowerSwitch);
  }


  //--------Switch ON--------
  if(SwitchState == true) {
    Rotation = MaxRotation;
    Delay = 0;
  }
  runProfile(ProfilePot);
  reset();
  Stop();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<







//----------------------------------RUN PROFILE----------------------------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void runProfile(int profile) {
  switch(profile) {

//----------Test----------
    case 0:
      while(SwitchState == true) {
        Rotation = analogRead(Distance)/2;
        tap(2);
        SwitchState = digitalRead(PowerSwitch);
        if(SwitchState == false) {break;}
        tap(4);
        SwitchState = digitalRead(PowerSwitch);
        if(SwitchState == false) {break;}
      }
    break;

//----------HillClimb Coin Grinder----------
    case 1:
      Rotation = 100;
      while(SwitchState == true) {
        tap(2);      
          delay(400);
        movement(6);
          //total delay = 5,180 ms
          ActiveDelay(5180);
          if(SwitchState == false) {break;}
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
    break;
//----------HillClimb Gem Grinder----------
    case 2:
      while(SwitchState == true) {

        SwitchState = digitalRead(PowerSwitch);
      }
    break;
//----------HillClimb arena pilot----------
    case 3:

movement(2);
delay(100);
movement(1);
ActiveDelay(500);
movement(2);
delay(100);
movement(1);



      SwitchState = digitalRead(PowerSwitch);
    
    break;
//----------HillClimb 2 wall rider----------
    case 4:

movement(2);
ActiveDelay(1000);
movement(1);



        SwitchState = digitalRead(PowerSwitch);
    
    break;
//----------Pinout player----------
    case 5:
      
      SwitchState = digitalRead(PowerSwitch);
    
    break;
//----------Does not commute player----------
    case 6:

movement(2);
delay(100);
movement(1);
delay(2900);
movement(2);
delay(500);
movement(1);
delay(100);
movement(4);
delay(500);
movement(3);
delay(600);
movement(2);
delay(100);
movement(1);
delay(3200);
movement(2);
delay(100);
movement(1);
delay(1900);
movement(4);
delay(200);
movement(3);
delay(500);
movement(4);
delay(300);
movement(3);
delay(800);
movement(2);
delay(100);
movement(1);
delay(100);
movement(2);
delay(300);
movement(1);
delay(300);
movement(2);
delay(700);
movement(1);
delay(100);
movement(4);
delay(200);
movement(3);
delay(200);
movement(4);
delay(100);
movement(3);
delay(400);
movement(4);
delay(100);
movement(3);
delay(5600);
movement(2);
delay(100);
movement(1);
delay(2500);
movement(2);
delay(400);
movement(1);
delay(100);
movement(4);
delay(300);
movement(3);
delay(1900);
movement(4);
delay(100);
movement(3);



      SwitchState = digitalRead(PowerSwitch);
    
    break;
//---------- ----------  
    case 7:
      Rotation = 100;
      while(SwitchState == true) {
        movement(8);
        delay(0);
        movement(7);
        movement(7);
        delay(0);
        movement(8);
        
        SwitchState = digitalRead(PowerSwitch);
      }
    break;
  }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




//-------------ACTIVE DELAY-------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//this delay breaks the loop as soon as the process is stopped
void ActiveDelay(int MaxDelay) {
  RemainingDelay = MaxDelay % 500;
  MaxDelay = (MaxDelay - RemainingDelay) / 500;
  while (DelayPart < MaxDelay) {
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {break;}
    DelayPart++;
    delay(500);
  }
  delay(RemainingDelay);
  RemainingDelay = 0;
  DelayPart = 0;
}

//This delay minds the FancyLight
void ActiveDelay2(int MaxDelay) {
  MaxDelay = MaxDelay / 2;
  while (DelayPart < MaxDelay) {
    FancyLight(5);
    DelayPart++;
    delayMicroseconds(1950);
  }
  DelayPart = 0;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void Stop() {
  while (0 == 0) {
    SwitchState = digitalRead(PowerSwitch);
    if(SwitchState == false) {
      break;
    }
    delay(10);
  }
}
