//========================= FANCY LIGHT =========================

#define PI 3.14159265359

void FancyLight(int Light) {
  
  // a sinus or a parabolic pattern would be more satisfying to watch than this linear pattern

  // light gets brighter
  if (LightIntensityUp == 1) {
    LightIntensity = LightIntensity + BrightnessStep;
    if (LightIntensity > 255) {
      LightIntensityUp = 0;
    }
  }
  else {
    // light is dimming
    LightIntensity = LightIntensity - BrightnessStep;
    // start it
    if (LightStatus == 0 && LightIntensity < -1000) {
      LightIntensity = 0;
      LightIntensityUp = 1;
      LightStatus = 1;
    }
    // go again
    if (LightStatus == 1 && LightIntensity < 0) {
      LightIntensity = 0;
      LightIntensityUp = 1;
      LightStatus = 0;
    }
  }

  if (LightIntensity >= 0 && LightIntensity <= 255) {
    switch (Light) {
      case 0:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 1:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 2:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, 0);
        break;
      case 3:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, 0);
        break;
      case 4:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 5:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 6:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 7:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, LightIntensity);
        break;
    }
  }
}



void pulseNtimes(int N, int Light) {
  LightIntensity = 0;
  for (int n=0; n<=N; n++) {
    while (LightIntensity < 255) {
      LightIntensity = LightIntensity +2;
      //Serial.println(LightIntensity);
      UpdateLight(Light);
      delay(2);
    }
    while (LightIntensity > 0) {
      LightIntensity = LightIntensity -2;
      //Serial.println(LightIntensity);
      UpdateLight(Light);
      delay(2);
    }
  }
}



void ColorMixer () {
  int Red = 0;
  int Green = 0;
  int Blue = 0;
  int Intensity = 0;
  float Hue = 0;

  while (interruptAutomation() == false) {
    Hue = analogRead(A2)/512.000;
    Intensity = analogRead(A1)/4;
    
    Red   = Intensity * (.5 + .5*sin( Hue        * PI));
    Green = Intensity * (.5 + .5*sin((Hue + 0.5) * PI));
    Blue  = Intensity * (.5 + .5*sin((Hue + 1  ) * PI));
    
    analogWrite(RedLight, Red);
    analogWrite(GreenLight, Green);
    analogWrite(BlueLight, Blue);

    
    /*  Marker 2
    Serial.print(Red); Serial.print(","); 
    Serial.print(Blue); Serial.print(","); 
    Serial.print(Green); Serial.print(","); 
    Serial.print(Hue); Serial.print(","); 
    Serial.println(Intensity);
    */
  }
}



void UpdateLight (int Light) {
    switch (Light) {
      case 0:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 1:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, 0);
        break;
      case 2:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, 0);
        break;
      case 3:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, 0);
        break;
      case 4:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 5:
        analogWrite(RedLight, 0);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 6:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, 0);
        analogWrite(BlueLight, LightIntensity);
        break;
      case 7:
        analogWrite(RedLight, LightIntensity);
        analogWrite(GreenLight, LightIntensity);
        analogWrite(BlueLight, LightIntensity);
        break;
    }
}
