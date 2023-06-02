// TCS230 or TCS3200 pins wiring to Arduino
// RIGHT COLOR SENSOR
#define RS0 33
#define RS1 34
#define RS2 35
#define RS3 36
#define RSOut 37
// LEFT COLOR SENSOR
#define LS0 32
#define LS1 31
#define LS2 30
#define LS3 29
#define LSOut 28

// Stores frequency read by the photodiodes
int RredFreq = 0;
int RgreenFreq = 0;
int RblueFreq = 0;
int LredFreq = 0;
int LgreenFreq = 0;
int LblueFreq = 0;

// Stores the red. green and blue colors
int RredCol = 0;
int RgreenCol = 0;
int RblueCol = 0;
int LredCol = 0;
int LgreenCol = 0;
int LblueCol = 0;

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
  
  // Setting the sensorOut as an input
  pinMode(RSOut, INPUT);
  pinMode(LSOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(RS0,HIGH);
  digitalWrite(RS1,LOW);
  digitalWrite(LS0,HIGH);
  digitalWrite(LS1,LOW);
  
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
  RredCol = map(RredFreq, 46, 322, 255, 0);
  // Printing the RED (R) value
  //Serial.print("RR = ");
  //Serial.print(RredCol);
  // if(RredCol <= 2000 && RredCol >= -1000){
  //   Serial.println("RIGHT - RED ");
  // }
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(RS2,HIGH);
  digitalWrite(RS3,HIGH);
  // Reading the output frequency
  RgreenFreq = pulseIn(RSOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  RgreenCol = map(RgreenFreq, 47, 329, 255, 0);
  // Printing the GREEN (G) value  
  //Serial.print(" RG = ");
  //Serial.print(RgreenCol);
  // if(RgreenCol <= 6000 && RgreenCol >= -1000){
  //   Serial.println(" RIGHT - GREEN ");
  // }
  
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(RS2,LOW);
  digitalWrite(RS3,HIGH);
  // Reading the output frequency
  RblueFreq = pulseIn(RSOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  RblueCol = map(RblueFreq, 41, 282, 255, 0);
  // Printing the BLUE (B) value 
  //Serial.print(" RB = ");
  //Serial.print(RblueCol);
  // if(RblueCol <= 1500 && RblueCol >= -2000){
  //   Serial.println(" RIGHT - BLUE ");
  // }
  delay(10);
  /////////////////////////////////////////////////////////////////////////

  ///////////////////// FOR LEFT COLOR SENSOR /////////////////////////////
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(LS2,LOW);
  digitalWrite(LS3,LOW);
  // Reading the output frequency
  LredFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  LredCol = map(LredFreq, 28, 235, 255, 0);
  // Printing the RED (R) value
  //Serial.print(" LR = ");
  //Serial.print(LredCol);
  // if(LredCol <= 2000 && LredCol >= -1000){
  //   Serial.println(" LEFT - RED ");
  // }
  delay(10);

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(LS2,HIGH);
  digitalWrite(LS3,HIGH);
  // Reading the output frequency
  LgreenFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  LgreenCol = map(LgreenFreq, 31, 255, 255, 0);
  // Printing the GREEN (G) value  
  //Serial.print(" LG = ");
  //Serial.print(LgreenCol);
  // if(LgreenCol <= 3000 && LgreenCol >= -1000){
  //   Serial.println(" LEFT - GREEN ");
  // }
  delay(10);

  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(LS2,LOW);
  digitalWrite(LS3,HIGH);
  // Reading the output frequency
  LblueFreq = pulseIn(LSOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  LblueCol = map(LblueFreq, 24, 204, 255, 0);
  // Printing the BLUE (B) value 
  //Serial.print(" LB = ");
  //Serial.println(LblueCol);
  // if(LblueCol <= 2040 && LblueCol >= 1000){
  //   Serial.println(" LEFT - BLUE ");
  // }
  // delay(10);
  // if(RredCol <= 0 && RgreenCol <=0 && RblueCol <= 0){
  // Serial.println("RIGHT - WHITE/FLOOR");  
  // }
  // else if(RredCol >= 10000 && RgreenCol >= 10000 && RblueCol >= 10000){

  //   Serial.println("RIGHT - BLACK");
  // }
  // if(LredCol <= 0 && LgreenCol <=0 && LblueCol <= 0){
  // Serial.println("LEFT - WHITE/FLOOR");   
  // }
  // else if(LredCol >= 10000 && LgreenCol >= 10000 && LblueCol >= 10000){
  //   Serial.println("LEFT - BLACK");
  // }
  Serial.print("Right Red = ");
  Serial.print(RredCol);
  Serial.print(" Right Green = ");
  Serial.print(RgreenCol);
  Serial.print(" Right Blue = ");
  Serial.print(RblueCol);
  Serial.print(" Left Red = ");
  Serial.print(LredCol);
  Serial.print(" Left Green = ");
  Serial.print(LgreenCol);
  Serial.print(" Right Blue = ");
  Serial.println(LblueCol);
  ////////////////////////////////////////////////////////////////////////////
  delay(100);
}
