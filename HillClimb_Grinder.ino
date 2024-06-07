//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//HillClimb Grinder
//Automate Mobile Games

//Created By SP4CEBAR - sp4cebar.com
//Based On Code Written By Nikodem Bartnik - nikodembartnik.pl

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//To Do
//- make ActiveDelay more accurate
//- make the profile recorder more accurate (ActiveDelay2)












//------------- VARIABLE AND PIN DECLARATION -------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define STEPPER1_PIN_1 5
#define STEPPER1_PIN_2 4
#define STEPPER1_PIN_3 3
#define STEPPER1_PIN_4 2

#define STEPPER2_PIN_1 13
#define STEPPER2_PIN_2 12
#define STEPPER2_PIN_3 8
#define STEPPER2_PIN_4 7

#define Profile A2
#define Speed A1
#define Distance A0

#define RedLight 9
#define BlueLight 10
#define GreenLight 11

#define PowerSwitch 6
#define ReadButtons A3

int CurrentStep = 0;
int StepNumber1 = 0;
int StepNumber2 = 0;
int RelativePosition1 = 0;
int RelativePosition2 = 0;

int MaxRotation = 50;
int Rotation = MaxRotation;
int Delay = 0;
int DelayPart = 0;
int RemainingDelay = 0;

int ProfilePot = 0;
int ConstantPot1Duration = 0;
int ConstantPot2Duration = 0;
bool Pot1Changed = 0;
bool Pot2Changed = 0;

int ButtonVal = 0;
int Button = 0;
int B3PressDuration = 0;
int DelayRecording = 0;
char receivedChar;
bool SwitchState = digitalRead(PowerSwitch);
bool editStepperPos = 0;
bool ProfileRecorderMode = 0;
bool endProfileRecMode = 0;
bool Stepper1Max = 0;
bool Stepper2Max = 0;

int LightIntensity = 0;
int LightStatus = 0;
bool LightIntensityUp = 0;
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//------------- SETUP -------------
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void setup() {
pinMode(STEPPER1_PIN_1, OUTPUT);
pinMode(STEPPER1_PIN_2, OUTPUT);
pinMode(STEPPER1_PIN_3, OUTPUT);
pinMode(STEPPER1_PIN_4, OUTPUT);

pinMode(STEPPER2_PIN_1, OUTPUT);
pinMode(STEPPER2_PIN_2, OUTPUT);
pinMode(STEPPER2_PIN_3, OUTPUT);
pinMode(STEPPER2_PIN_4, OUTPUT);

pinMode(Profile, INPUT);
pinMode(Speed, INPUT);
pinMode(Distance, INPUT);

pinMode(RedLight, OUTPUT);
pinMode(BlueLight, OUTPUT);
pinMode(GreenLight, OUTPUT);

pinMode(PowerSwitch, INPUT);
pinMode(ReadButtons, INPUT);

Serial.begin(9600);
Serial.println("<Arduino is ready>");
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
