#include <Servo.h>

Servo Gripper;  // create servo object to control a servo
Servo Arm;  // create servo object to control a servo

int GripperPosition = 200; 
int ArmPosition = 151; 
int PWMSignal;

void setup() {
  Gripper.attach(23);  // attaches the servo on pin 23 to the servo object
  Arm.attach(22);  // attaches the servo on pin 22 to the servo object
}

void loop() 
{
  // mapping actual position for PWM signals
  int val1 = map(GripperPosition, 0, 300, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  int val2 = map(ArmPosition, 0, 300, 0, 180); // scale it to use it with the servo (value between 0 and 180)

  Gripper.write(val1); // sets the servo position according to the scaled value
  Arm.write(val2); // sets the servo position according to the scaled value
  delay(100); // waits for the servo to get there
}
