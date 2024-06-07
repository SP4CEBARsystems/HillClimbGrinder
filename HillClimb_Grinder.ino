//----------------------------------------------------------------
//- HillClimb Grinder
//- Automate Mobile Games
//----------------------------------------------------------------
//- Created By SP4CEBAR - sp4cebar.com  /  youtube.com/sp4cebar
//----------------------------------------------------------------


//Arduino Wiring
//0  : [RX Not Connected]
//1  : [TX Not Connected]
//2  : Stepper 1 pin 4
//3  : Stepper 1 pin 3
//4  : Stepper 1 pin 2
//5  : Stepper 1 pin 1
//6  : Audio out
//7  : Stepper 2 pin 4
//8  : Stepper 2 pin 3
//9  : Led Red
//10 : Led Green
//11 : Led Blue
//12 : Stepper 2 pin 2
//13 : Stepper 2 pin1

//A0 : buttons
//A1 : speed
//A2 : profile
//A3 : [Not Connected]
//A4 : [Not Connected]
//A5 : [Not Connected]




// To Do:

//- make the hardware more accurate 
//  - better conducting surface (some kind of a conducting gel?) (contact spray?)
//  - or solidify the stepper-stand, so the stylus pens can be used
//  - try to get the arms to be attached more solidly

//- record more profiles


//Bugs:
//- speed pot still keeps activating, Probably a hardware fault (a bad connection causes a lot of noise)
//  - Fix the noise:
//    - Solidify the connector
//    - contact spray
//    - appropriate noise barriers



//==== DONE ====

//Added Features
//- little programs
//  - DONE color mixer
//  - DONE sound generator

//- DONE add more profiles to the interface
//- DONE ten possible positions for profile pot
//- DONE profile pot at minimum -> previous menu
//- DONE profile pot at maximum -> next menu
//- DONE four menus in total, so 4*8 = 32 profiles in total

//- profile recorder: send this text to recorder output (serial monitor): Serial.print("if (interruptAutomation() == true) {break;}")

//- make the profile recorder more accurate
//  - profileRecorder: Store the timestamp before doing anything to increase accuracy

//Fixed Bugs:
//- Fixed Changing profile mode, disables color (and more)
//- Fixed FancyLight is still too fast
//- Speed Pot Interrupted Home Menu + Start sounds were interrupted by speedpot -> Noise Barrier
//- Input() loop time seems slower than before, it is serial printing... -> Comment out all the temporary serial printing commands







//------------- VARIABLE AND PIN DECLARATION -------------
 
#define STEPPER1_PIN_1 2
#define STEPPER1_PIN_2 3
#define STEPPER1_PIN_3 4
#define STEPPER1_PIN_4 5

#define STEPPER2_PIN_1 7
#define STEPPER2_PIN_2 8
#define STEPPER2_PIN_3 12
#define STEPPER2_PIN_4 13

#define RedLight 9
#define BlueLight 10
#define GreenLight 11

#define Profile A2
#define Speed A1

#define AudioPin 6
#define ReadButtons A0

int StepNumber1 = 0;
int StepNumber2 = 0;
int RelativePosition1 = 0;
int RelativePosition2 = 0;

int MaxRotation = 50;
int Rotation = MaxRotation;
int Delay = 0;
int DelayPart = 0;
int RemainingDelay = 0;
int RawSpeedPot = 0;
int SpeedPot = 0;
long TimeStamp = 0;    //Bug-Memorial: int instead of long -> micros() kept overflowing
long StartTime1 = 0;
long ProfileStartTime = 0;
long RecorderStartTime = 0;
long TestMicros = 0;

int RawProfilePot = 0;
int ProfilePot = 0;
int TProfileNo = 0;
int ProfileNo = 0;
int Menu = 0;
int ConstantPot1Duration = 0;
int ConstantPot2Duration = 0;
bool Pot1Changed = 0;
bool Pot2Changed = 0;
int InterruptTime = 0;

int ButtonVal = 0;
int Button = 0;
int B3PressDuration = 0;
char receivedChar;
bool SwitchState = 0;
bool editStepperPos = 0;
bool ProfileRecorderMode = 0;
bool endProfileRecMode = 0;
bool Stepper1Max = 0;
bool Stepper2Max = 0;

int LightColor = 1;
int StartFL = 0;
int LightIntensity = 0;
int LightStatus = 1;
bool LightIntensityUp = 1;
int BrightnessStep = 1;



//------------- SETUP -------------
 
void setup() {

//stepper 1
pinMode(STEPPER1_PIN_1, OUTPUT);
pinMode(STEPPER1_PIN_2, OUTPUT);
pinMode(STEPPER1_PIN_3, OUTPUT);
pinMode(STEPPER1_PIN_4, OUTPUT);

//stepper 2
pinMode(STEPPER2_PIN_1, OUTPUT);
pinMode(STEPPER2_PIN_2, OUTPUT);
pinMode(STEPPER2_PIN_3, OUTPUT);
pinMode(STEPPER2_PIN_4, OUTPUT);

//potmeters
pinMode(Profile, INPUT);
pinMode(Speed, INPUT);

//Multicolored LED
pinMode(RedLight, OUTPUT);
pinMode(BlueLight, OUTPUT);
pinMode(GreenLight, OUTPUT);

//Miscellaneous
//pinMode(PowerSwitch, INPUT);
pinMode(AudioPin, OUTPUT);
pinMode(ReadButtons, INPUT);

Serial.begin(9600);
Serial.println("<Arduino is ready>");

//Uncomment to enable testing:
//Testing();
}




void Testing() {
  //========== Testing SPACE ==========
  
  if (0){
    String TestString = "Hello World";
    int TestInt = 42;
  
  //Serial.println("Hello " "World and " + TestString + TestInt);
  
  //Serial.println("Number " + TestInt);
  //Corrupts Serial Communication
  }
  
  if (0) {
  //==== TIMING TEST ====
  //  - Time commands
  //  - check the execution times online
  
    //Time at A (Start of recording) = 216 milliseconds
    
    //  NAME                | Start - End = Execution Time (Milliseconds) 
    //===========================================================================
    //None                     220-216= 4 (1x request micros + 1x store var)
    //C = 1;                   220-216= 4 (No-Time)
    //int C = 0;               220-216= 4
  
    //TimeStamp = micros() - RecorderStartTime;  224-216= 8
    //StartAt(0);              228-216= 12
    
    //Serial.println();        240-216= 24
    //Serial.println("Test");  272-216= 56
    
    //Serial.println("1");     252-216= 36
    //Serial.println("12");    260-216= 44
    //Serial.println("123");   268-216= 52
    //Serial.println("1234");  272-216= 56
    //Serial.println("12345"); 280-216= 64
    
    //Serial.println(2);       296-216= 80
    
    //analogRead(A0);          424-216= 208
    //analogRead(A1);          424-216= 208
    //analogRead(Profile);     424-216= 208
    //analogWrite(9,255);      232-216= 16
    //digitalWrite(2,HIGH);    224-216= 8
    //digitalRead(2);          224-216= 8
    
    //Rotation = 50;
    //movement(2);             21780-220= 21560
    
      int A = 0;
      int B = 0;
      
    
      //Rotation = 50;
      
      A = micros();
      //Commands to time:
  
      B = micros();
      
      Serial.print(B);
      Serial.print("-");
      Serial.print(A);
      Serial.print("= ");
      Serial.println(B-A);
  }
}
