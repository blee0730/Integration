#include <Servo.h>
#define PS A14 //defines the pressure sensors pin
#define echoPin 17 // attach Echo of HC-SR04
#define trigPin 18 //attach Trig of HC-SR04

long duration;
int distance;

Servo Gripper;  // create servo object to control a servo

int GripperClose = 120;
int GripperOpen = 170;
int GripperPosition = 0; //initialize gripper position
float FS_Threshold = 7;
int Size = 0;

void setup() {
  Gripper.attach(39);  // attaches the servo on pin 39 to the servo object
  pinMode(PS, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Gripper.write(GripperOpen); //Open gripper
  Serial.begin(115200);
}

void loop(){
  readUltrasonic();

  if(distance == 10 || distance == 9)
  {
    grab();
  }
}

void grab()
{
  for(int i = 0; i <= 55; i++)
  {
    readUltrasonic();
    int Press = analogRead(PS); //Reads force on sensor //Testing purposes
    float Force = Press/5.5;

    Serial.println(Force);
    Gripper.write(GripperOpen-i); //Decreases the gripper's position from open one step at a time
    GripperPosition = GripperOpen-i; //Set gripper position
    delay(100);
    if(Force >= FS_Threshold) //if the force sensor reads a pressure
    {
      Gripper.write(GripperPosition); //setting the gripper position
      Serial.println(GripperPosition);
      if(GripperPosition == 131) //if the gripper position is more closed
      {
        Size = 0;
      }

      if(GripperPosition >= 140 && GripperPosition <= 160)
      {
        Size = 1;
      }
      i = 60;
      break; //Exit the for loop and set gripper position in place
    }
  }
  // Serial.println(GripperPosition);
  // Serial.println(Size);
}

void readUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (send & receive)
  // Serial.println(distance);
  delay(10);
}