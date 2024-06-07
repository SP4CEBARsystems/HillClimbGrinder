void FancyLight(int Light) {
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

  //a sinus or a parabolic pattern would be more satisfying to watch than this linear pattern
  if (LightIntensityUp == 1) {
    LightIntensity++;
    if (LightIntensity > 255) {
      LightIntensityUp = 0;
    }
  }
  else {
    LightIntensity--;
    if (LightStatus == 0) {
      if (LightIntensity < -1000) {
        LightIntensity = 0;
        LightIntensityUp = 1;
        LightStatus = 1;
      }
    }
    if (LightStatus == 1) {
      if (LightIntensity < 0) {
        LightIntensity = 0;
        LightIntensityUp = 1;
        LightStatus = 0;
      }
    }
  }
}
