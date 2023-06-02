//L298 Motor Controller Pin Assignment
// Motor A pin connections
int enA = 1;
int in1 = 2;
int in2 = 3;
// Motor B pin connections
int enB = 4;
int in3 = 5;
int in4 = 6;

// Motor C pin connections
int enC = 7;
int in5 = 8;
int in6 = 9;

// Motor D pin connections
int enD = 10;
int in7 = 11;
int in8 = 12;

void setup()
{
	// Set all motor controller pins as outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
	
	// Initial state - Turn off all the motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}

void loop() 
{
  stop();
  delay(500);
  movFW(100);
  delay(1000);
  stop();
  delay(500);
  movBW(100);
  delay(1000);
  stop();
  delay(500);
  movCW(100);
  delay(1000);
  stop();
  delay(500);
  movCCW(100);
  delay(1000);
  stop();
  delay(500);
  movLFT(100);
  delay(1000);
  stop();
  delay(500);
  movRT(100);
  delay(1000);
  stop();
  delay(500);
  movDiagRT(100);
  delay(1000);
  stop();
  delay(500);
  movDiagLFT(100);
  delay(1000);
  delay(20000);
}

// stop any movement
void stop(){
  // move forward with 0% speed - For PWM value 0
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  analogWrite(enC, 0);
  analogWrite(enD, 0);
  
  // Turn off all the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);  
}

// move forward
void movFW(int speed)
{
  int PWMval = 255*speed/100;
  // move forward with 60% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
	analogWrite(enA, PWMval);
	analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);
  // Rotate left and right wheels in clockwise direction - Move forward
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(50);
}

// move backward
void movBW(int speed)
{
  int PWMval = 255*speed/100;
  // move backward with 60% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
	analogWrite(enA, PWMval);
	analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);
  // Rotate left and right wheels in anti-clockwise direction - Move backward
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH); 
  delay(50);
}

// turn left
void movCW(int speed)
{
  int PWMval = 255*speed/100;
  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
	analogWrite(enA, PWMval);
	analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);
  // Rotate left wheel clockwise and right wheel in anti-clockwise direction - Spin clockwise/Turn right
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(50);
}

// turn right
void movCCW(int speed)
{
  int PWMval = 255*speed/100;
  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
	analogWrite(enA, PWMval);
	analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);
  // Rotate left wheel anti-clockwise and right wheel in clockwise direction - Spin anti-clockwise/Turn left
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(50);
}

//move left
void movLFT(int speed){
  int PWMval = 255*speed/100;

  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
  analogWrite(enA, PWMval);
  analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);

  // Rotate left wheel anti-clockwise and right wheel in clockwise direction - Spin anti-clockwise/Turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(50);
}

//move right
void movRT(int speed){
   int PWMval = 255*speed/100;

  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
  analogWrite(enA, PWMval);
  analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);

  // Rotate left wheel anti-clockwise and right wheel in clockwise direction - Spin anti-clockwise/Turn left
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(50);
}

//move diagonally right
void movDiagRT(int speed){
  int PWMval = 255*speed/100;

  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
  analogWrite(enA, PWMval);
  analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);

  // Rotate left wheel anti-clockwise and right wheel in clockwise direction - Spin anti-clockwise/Turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(50);
}

//move diagonally left
void movDiagLFT(int speed){
  int PWMval = 255*speed/100;

  // turn with 30% speed - For PWM values varies between 0 (no speed) and 255 (full speed)
  analogWrite(enA, PWMval);
  analogWrite(enB, PWMval);
  analogWrite(enC, PWMval);
  analogWrite(enD, PWMval);

  // Rotate left wheel anti-clockwise and right wheel in clockwise direction - Spin anti-clockwise/Turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  delay(50);
}