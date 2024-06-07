//========================= SOUND =========================
//----------------------------------------------------------------
// the defined frequencies are from the built-in examples of the Arduino IDE
// The TETRIS theme data if from LukaCyca - https://github.com/lukecyca/TetrisThemeArduino/blob/master/TetrisThemeArduino.ino
//----------------------------------------------------------------

#define _R 0

#define _B0  31
#define _C1  33
#define _CS1 35
#define _D1  37
#define _DS1 39
#define _E1  41
#define _F1  44
#define _FS1 46
#define _G1  49
#define _GS1 52
#define _A1  55
#define _AS1 58
#define _B1  62
#define _C2  65
#define _CS2 69
#define _D2  73
#define _DS2 78
#define _E2  82
#define _F2  87
#define _FS2 93
#define _G2  98
#define _GS2 104
#define _A2  110
#define _AS2 117
#define _B2  123
#define _C3  131
#define _CS3 139
#define _D3  147
#define _DS3 156
#define _E3  165
#define _F3  175
#define _FS3 185
#define _G3  196
#define _GS3 208
#define _A3  220
#define _AS3 233
#define _B3  247
#define _C4  262
#define _CS4 277
#define _D4  294
#define _DS4 311
#define _E4  330
#define _F4  349
#define _FS4 370
#define _G4  392
#define _GS4 415
#define _A4  440
#define _AS4 466
#define _B4  494
#define _C5  523
#define _CS5 554
#define _D5  587
#define _DS5 622
#define _E5  659
#define _F5  698
#define _FS5 740
#define _G5  784
#define _GS5 831
#define _A5  880
#define _AS5 932
#define _B5  988
#define _C6  1047
#define _CS6 1109
#define _D6  1175
#define _DS6 1245
#define _E6  1319
#define _F6  1397
#define _FS6 1480
#define _G6  1568
#define _GS6 1661
#define _A6  1760
#define _AS6 1865
#define _B6  1976
#define _C7  2093
#define _CS7 2217
#define _D7  2349
#define _DS7 2489
#define _E7  2637
#define _F7  2794
#define _FS7 2960
#define _G7  3136
#define _GS7 3322
#define _A7  3520
#define _AS7 3729
#define _B7  3951
#define _C8  4186
#define _CS8 4435
#define _D8  4699
#define _DS8 4978



// TETRIS theme
int lead_notes[] = {
  // part 1
  _E5, _B4, _C5, _D5, _C5, _B4, _A4, _A4, _C5, _E5, _D5, _C5, _B4, _B4, _C5, _D5, _E5, _C5, _A4, _A4, _R,
  _D5, _F5, _A5, _G5, _F5, _E5, _C5, _E5, _D5, _C5, _B4, _B4, _C5, _D5, _E5, _C5, _A4, _A4, _R,

  // part 2
  _E4, _C4, _D4, _B3, _C4, _A3, _GS3, _B3,
  _E4, _C4, _D4, _B3, _C4, _E4, _A4, _A4, _GS4, _R
};

float lead_times[] = {
  // part 1
  1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
  1.5, 0.5, 1.0, 0.5, 0.5, 1.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,

  // part 2
  2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0,
  2.0, 2.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 3.0, 1.0
};


//Play a predefined set of sounds
void playSound(int sound) {
  switch (sound) {
    
    case 1: //BEEP 1
    tone(AudioPin, _C4, 500);
    delay(100);
    tone(AudioPin, _C5, 250);
    break;
    
    case 2: //TETRIS
    for(int AudioTime = 0; AudioTime < 58; AudioTime++) {
      tone(AudioPin, lead_notes[AudioTime], 300);
      delay(lead_times[AudioTime]*250);
      noTone(AudioPin);
      delay(5);
      if (interruptAutomation() == true) {break;}
    }
    break;
  }
}

void SoundGenerator() {
  int Frequency = 0;
  while (interruptAutomation() == false) {
    Frequency = analogRead(A2)*4;
    tone(AudioPin, Frequency, 250);
  }
}

void MusicGenerator() {
  int Octave = 0;
  int Pitch  = 0;
  int Frequency = 0;
  int SoundType = 0;
  
  while (interruptAutomationF() == false) {
  
  ButtonRead();
  switch(Button) {
    case 0: //sound off
      SoundType=10;
    break;
    case 1: //play sound
      SoundType=0;
    break;
    case 2: //sound off
      SoundType=10;
    break;
    case 3: //play lower sound
      SoundType=-1;
    break;
    case 4: //play higher sound 
      SoundType=1;
    break;
  }
    if (SoundType==10){
      noTone(AudioPin);
    } else {
      Octave =    (analogRead(A1)/128)-3;
      Pitch  = map(analogRead(A2),0,1023,1,12);
      Frequency = 440*pow(1.059463094359, ((Octave+SoundType)*12+Pitch));
      tone(AudioPin, Frequency, 100);
    }
    /*  MARKER 3 
      Serial.print(Pitch);  Serial.print(",");
      Serial.print(Octave);  Serial.print(",");
      Serial.println(Frequency);
    */
  }
}


void MotorMusic() {
  //The Motors Are Not Loud Enough
  Rotation = 4;
  Delay = 0;
}
