int events[128];
unsigned long deltaTimes[128];
int maxEvent = 0;

void recordArray(){
  unsigned long startTime = millis();
  unsigned int  eventId   = 0;
  int event=0;
  while( interruptAutomation() == false ){
    do {
      ButtonRead ();
      event = buttonEvent(Button);
      delay(1);
    } while(event==0 && interruptAutomation() == false);
    
    deltaTimes [eventId] = millis() - startTime;
    startTime            = millis();
    events     [eventId] = event;
    movement   ( event );
    eventId++;
    maxEvent = eventId;
  }
}

void playArray(){
  unsigned long startTime = millis();
  unsigned int  eventId   = 0;
  while( interruptAutomation() == false ){
    while( eventId<maxEvent && interruptAutomation() == false ){
      ActiveDelay( deltaTimes [eventId] );
      movement   ( events     [eventId] );
      eventId++;
    }
  }
}

int buttonEvent(int button){
  switch (Button) {

    //Right and Left
    case 4:
      if (Stepper1Max == 0 && Stepper2Max == 0) {
        Stepper1Max = 1;
        Stepper2Max = 1;
        return 6;  //both on
      }
      if (Stepper1Max == 0) {
        Stepper1Max = 1;
        return 4;  //left on
      }
      if (Stepper2Max == 0) {
        Stepper2Max = 1;
        return 2;  //right on
      }
      break;

      
    //Left
    case 1:
      if (Stepper1Max == 0 && Stepper2Max == 1) {
        Stepper1Max = 1;
        Stepper2Max = 0;
        return 7;  //left on and right off
      }
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        Stepper2Max = 0;
        return 1;  //right off
      }
      if (Stepper1Max == 0) {
        Stepper1Max = 1;
        return 4;  //left on
      }
      break;

      
    //Right (Stepper 2)
    case 3:
      if (Stepper1Max == 1 && Stepper2Max == 0) {
        Stepper1Max = 0;
        Stepper2Max = 1;
        return 8;  //right on and left off
      }
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        Stepper1Max = 0;
        return 3;  //left off
      }
      if (Stepper2Max == 0) {
        Stepper2Max = 1;
        return 2;  //right on
      }
      break;

      
    //Idle
    case 0:
      if (Stepper1Max == 1 && Stepper2Max == 1) {
        Stepper1Max = 0;
        Stepper2Max = 0;
        return 5;  //both off
      }
      if (Stepper1Max == 1) {
        Stepper1Max = 0;
        return 3;  //left off
      }
      if (Stepper2Max == 1) {
        Stepper2Max = 0;
        return 1;  //right off
      }
    break;
  }
  return 0;
}
