//========================= MAIN LOOP =========================
//  Contents:
//   - void loop()
//   - Run Profile
//   - Active Delay
//=============================================================




//---------------------- LOOP --------------------------

void loop() {
  //--------Switch OFF-------- (set up steppers, select profile)
  if(SwitchState == false) {
    Rotation = 4;
  }

  while(SwitchState == false) {
    //serialCommunication();
    if (ProfileRecorderMode == 0) {
      userInput();
    }
    else {
      ProfileRecorder();
    }
    //FancyLight(5);
    delay(2);
  }


  //--------Switch ON-------- (run profile)
  if(SwitchState == true) {
    Rotation = MaxRotation;
    Delay = 0;
    playSound(1);
    delay(250);
  }
  runProfile(ProfileNo);
  reset();
  Stop();
}








//-------------ACTIVE DELAY------------- (a delay function which checks when the profile is stopped)
 

//this delay breaks the loop as soon as the process is stopped
void ActiveDelay(unsigned long  MaxDelay) {
  unsigned long startTime = millis();
  while (( millis() - startTime <= MaxDelay ) && interruptAutomation() == false) {
    delay(1);
  }
}


//StartAt() waits for a specific time in microseconds before continuing the program

void StartAt(unsigned long TimeStamp) {
  while((micros() - ProfileStartTime < TimeStamp) && interruptAutomation() == false){
    delay(1);
  }
}


//green indicator light to show that the profile has ended

void Stop() {
  BrightnessStep = 5;
  while (0 == 0) {
    if (interruptAutomation() == true) {break;}
    FancyLight(3);
    delay(10);
  }
}
