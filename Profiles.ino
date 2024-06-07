//========================= RUN PROFILE =========================

void runProfile(int profile) {
  switch(profile) {
//MENU 0
  //Test
    case 0:
    break;

  //HillClimb Coin Grinder
    case 1:
      Rotation = 100;
      while(SwitchState == true) {
        tap(2);      
          delay(400);
        movement(6);
          ActiveDelay(5180);
          if (interruptAutomation() == true) {break;}
        movement(3);
          delay(500);
          if (interruptAutomation() == true) {break;}
        movement(1);
        movement(4);
          delay(500);
          if (interruptAutomation() == true) {break;}
        movement(3);
        movement(2);
          delay(500);
          if (interruptAutomation() == true) {break;}
        movement(1);
          ActiveDelay(23000);
          if (interruptAutomation() == true) {break;}
        tap(2);
          delay(1000);
          if (interruptAutomation() == true) {break;}
      }
    break;
  //HillClimb Gem Grinder
    case 2:
      while(SwitchState == true) {
        
        if (interruptAutomation() == true) {break;}
      }
    break;
  //HillClimb arena pilot
    case 3:

ProfileStartTime = micros();
StartAt(1000000);
movement(2);
StartAt(1100000);
movement(1);
StartAt(2000000);
movement(2);
StartAt(2100000);
movement(1);



        if (interruptAutomation() == true) {break;}
    
    break;
  //HillClimb 2 wall rider
    case 4:

ProfileStartTime = micros();
StartAt(1923);
movement(2);
StartAt(2077);
movement(1);
StartAt(3051);
movement(2);
StartAt(3206);
movement(1);





            if (interruptAutomation() == true) {break;}
    
    break;
  //Pinout player
    case 5:
      ProfileStartTime = micros();


      if (interruptAutomation() == true) {break;}

    break;
    //Does not commute player
    case 6:
      ProfileStartTime = micros();
      
            StartAt(2576944);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(2763696);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(5533504);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(5977040);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(7033912);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(7538648);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(8042512);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(8229248);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(8607560);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(8917752);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(9449264);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(9635992);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(10710232);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(10970352);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(13073960);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(13464176);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(13988560);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(14421072);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(15819856);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(16460960);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(16983792);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(17225416);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(18262464);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(18450240);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(20883072);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(21094240);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(23957400);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(24524984);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(25115488);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(25760848);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(26067804);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(26396048);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(29250880);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(29505440);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(30663856);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(31121928);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(32103560);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(32761672);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(33318280);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(33747160);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(36269632);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(36457400);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(37681688);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(38258928);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(38557752);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(39195448);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(39598816);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(40417480);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(40923848);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(41178360);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(42515152);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(42702912);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(44276232);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(44732232);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(45919912);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(46301448);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(47367568);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(47855408);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(49169064);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(49708008);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(50072448);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(50324080);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(50860160);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(51248152);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(52519800);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(52707608);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(55749952);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(56359616);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(57792848);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(58325232);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(58837328);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(59050624);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(62298872);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(62486664);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(64306016);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(65579224);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(65913856);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(66101640);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(66547168);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(67189160);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(67706840);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(68517480);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(69202944);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(69390760);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(70561024);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(70748800);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(73622952);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(73823640);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(74437696);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(74640576);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(74970656);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(75158472);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(75527336);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(75715128);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(76400640);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(76588424);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(77014576);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(77230032);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(77562560);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(77750328);
      movement(1);
      if (interruptAutomation() == true) {break;}
      StartAt(78668152);
      movement(4);
      if (interruptAutomation() == true) {break;}
      StartAt(79565640);
      movement(3);
      if (interruptAutomation() == true) {break;}
      StartAt(79798640);
      movement(2);
      if (interruptAutomation() == true) {break;}
      StartAt(80693296);
      movement(1);
      if (interruptAutomation() == true) {break;}

      
      if (interruptAutomation() == true) {break;}
    break;
  //  
    case 7:
      Rotation = 100;
      while(SwitchState == true) {
        movement(8);
        delay(0);
        movement(7);
        movement(7);
        delay(0);
        movement(8);
        
        if (interruptAutomation() == true) {break;}
      }
    break;
    
//MENU 1
  //
    case 8:
    break;

  //
    case 9:  //Left on,off, right on,off, ... loop
      while(SwitchState == true) {
        Rotation = analogRead(Speed)/2;
        tap(2);
            if (interruptAutomation() == true) {break;}
        if(SwitchState == false) {break;}
        tap(4);
            if (interruptAutomation() == true) {break;}
        if(SwitchState == false) {break;}
      }
    break;

  //
    case 10:  //Timing Accuracy Sesting
      TestMicros = micros();
      StartAt(TestMicros+1000000);
      tap(2);
      StartAt(TestMicros+2000000);
      tap(2);
    break;

  //
    case 11:
    break;

  //
    case 12:
    break;

  //hillclimb racing arcade grinder
    case 13:
    while( interruptAutomation() == false ){
        ActiveDelay( 500 );
        movement   ( 6 );  //both on
        ActiveDelay( 500 );
        movement   ( 3 );  //left off
        ActiveDelay( 500 );
        movement   ( 1 );  //right off
        ActiveDelay( 500 );
        movement   ( 2 );  //right on
        ActiveDelay( 500 );
        movement   ( 1 );  //right off
    }
    break;

  //
    case 14:
    recordArray();
    break;

  //
    case 15:
    playArray();
    break;

  //

//MENU 2
    case 16:
    break;

  //
    case 17:
    break;

  //
    case 18:
    break;

  //
    case 19:
    break;

  //
    case 20:
    break;

  //
    case 21:
    break;

  //
    case 22:
    break;

  //
    case 23:
    break;

  //
    //MENU 3
    case 24:
    break;

  //
    case 25:
    break;

  //
    case 26:
    break;

  //
    case 27:
    break;

  //Color Mixer
    case 28:
      ColorMixer();
    break;

  //Music Generator
    case 29:
      MusicGenerator();
    break;

  //Sound Generator
    case 30:
      SoundGenerator();
    break;

  //Tetris theme
    case 31:
      while(SwitchState == true) {
        playSound(2);
        if (interruptAutomation() == true) {break;}
      }
    break;
  }
}
