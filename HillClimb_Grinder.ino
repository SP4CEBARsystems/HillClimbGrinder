#include <AccelStepper.h>
#include <MultiStepper.h>

void setup() {


AccelStepper stepper1(5,6,7,8);
AccelStepper stepper2(9,10,11,12);

stepper1.setMaxSpeed(2000);
stepper1.setAcceleration(1000);

stepper1.disableOutputs();


stepper2.setMaxSpeed(2000);
stepper2.setAcceleration(1000);

stepper2.disableOutputs();


}

void loop() {
  // put your main code here, to run repeatedly:

targetPosition(100)
delay(1000);

targetPosition(-100)
delay(1000);

targetPosition(100)
delay(1000);

targetPosition(-100)
delay(1000);

}
