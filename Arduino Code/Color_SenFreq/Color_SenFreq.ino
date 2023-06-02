// TCS230 or TCS3200 pins wiring to Arduino
// MIDDLE COLOR SENSOR
#define MS0 19
#define MS1 20
#define MS2 21
#define MS3 22
#define MSOut 23
// LEFT COLOR SENSOR
#define LS0 33
#define LS1 34
#define LS2 35
#define LS3 36
#define LSOut 37
//RIGHT COLOR SENSOR
#define RS0 32
#define RS1 31
#define RS2 30
#define RS3 29
#define RSOut 28

// Stores frequency read by the photodiodes
int RredFreq = 0;
int RgreenFreq = 0;
int RblueFreq = 0;
int LredFreq = 0;
int LgreenFreq = 0;
int LblueFreq = 0;
int MredFreq = 0;
int MgreenFreq = 0;
int MblueFreq = 0;

// Stores the red. green and blue colors
int RredCol = 0;
int RgreenCol = 0;
int RblueCol = 0;
int LredCol = 0;
int LgreenCol = 0;
int LblueCol = 0;
int MredCol = 0;
int MgreenCol = 0;
int MblueCol = 0;

void setup() 
{
  // Setting the outputs
  pinMode(RS0, OUTPUT);
  pinMode(RS1, OUTPUT);
  pinMode(RS2, OUTPUT);
  pinMode(RS3, OUTPUT);
  pinMode(LS0, OUTPUT);
  pinMode(LS1, OUTPUT);
  pinMode(LS2, OUTPUT);
  pinMode(LS3, OUTPUT);
  pinMode(MS0, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(RSOut, INPUT);
  pinMode(LSOut, INPUT);
  pinMode(MSOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(RS0,HIGH);
  digitalWrite(RS1,LOW);
  digitalWrite(LS0,HIGH);
  digitalWrite(LS1,LOW);
  digitalWrite(MS0, HIGH);
  digitalWrite(MS1,LOW);
  
  // Begins serial communication
  Serial.begin(115200);
}

void loop() 
{
  ///////////////////// FOR RIGHT COLOR SENSOR /////////////////////////////
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(RS2,LOW);
  digitalWrite(RS3,LOW);
  // Reading the output frequency
  RredFreq = pulseIn(RSOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  RredCol = map(RredFreq, 0, 40, 0, 255);
  // Printing the RED (R) value
  Serial.print("RR = ");
  Serial.print(RredFreq);
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(RS2,HIGH);
  digitalWrite(RS3,HIGH);
  // Reading the output frequency
  RgreenFreq = pulseIn(RSOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  RgreenCol = map(RgreenFreq, 0, 80, 0, 255);
  // Printing the GREEN (G) value  
  Serial.print(" RG = ");
  Serial.print(RgreenFreq);
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(RS2,LOW);
  digitalWrite(RS3,HIGH);
  // Reading the output frequency
  RblueFreq = pulseIn(RSOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  RblueCol = map(RblueFreq, 0, 100, 0, 255);
  // Printing the BLUE (B) value 
  Serial.print(" RB = ");
  Serial.print(RblueFreq);
  delay(10);
  /////////////////////////////////////////////////////////////////////////

  ///////////////////// FOR LEFT COLOR SENSOR /////////////////////////////
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(LS2,LOW);
  digitalWrite(LS3,LOW);
  // Reading the output frequency
  LredFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  LredCol = map(LredFreq, 0, 40, 0, 255);
  // Printing the RED (R) value
  Serial.print(" LR = ");
  Serial.print(LredFreq);
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(LS2,HIGH);
  digitalWrite(LS3,HIGH);
  // Reading the output frequency
  LgreenFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  LgreenCol = map(LgreenFreq, 0, 80, 0, 255);
  // Printing the GREEN (G) value  
  Serial.print(" LG = ");
  Serial.print(LgreenFreq);
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(LS2,LOW);
  digitalWrite(LS3,HIGH);
  // Reading the output frequency
  LblueFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  LblueCol = map(LblueFreq, 0, 100, 0, 255);
  // Printing the BLUE (B) value 
  Serial.print(" LB = ");
  Serial.println(LblueFreq);
  delay(10);
  ////////////////////////////////////////////////////////////////////////////
  
  digitalWrite(MS2,LOW);
  digitalWrite(MS3,LOW);
  // Reading the output frequency
  MredFreq = pulseIn(MSOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  MredCol = map(RredFreq, 0, 40, 0, 255);
  // Printing the RED (R) value
  Serial.print("MR = ");
  Serial.print(MredFreq);
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(MS2,HIGH);
  digitalWrite(MS3,HIGH);
  // Reading the output frequency
  MgreenFreq = pulseIn(MSOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  MgreenCol = map(MgreenFreq, 0, 80, 0, 255);
  // Printing the GREEN (G) value  
  Serial.print(" MG = ");
  Serial.print(MgreenFreq);
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(MS2,LOW);
  digitalWrite(MS3,HIGH);
  // Reading the output frequency
  MblueFreq = pulseIn(MSOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  MblueCol = map(MblueFreq, 0, 100, 0, 255);
  // Printing the BLUE (B) value 
  Serial.print(" MB = ");
  Serial.print(MblueFreq);
   delay(10);
  delay(100);
}
