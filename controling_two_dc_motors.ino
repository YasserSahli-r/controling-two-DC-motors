// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;
/*
// Speed control potentiometers
int SpeedControl1 = A0;
int SpeedControl2 = A1;

// Motor Speed Values - Start at zero
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;
*/
void setup() {
  // put your setup code here, to run once:
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}
void demo1(){
  // this function will turn the motors in both directions at fixed speed
  // Turn motor A
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 200 out of possible range 0-255
  
  analogWrite(enA, 200);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

 // Set speed to 200 out of possible range 0-255
  
  analogWrite(enB, 200);

  delay(2000);

  // now change motor directions

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(2000);

  //now turn off motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void demo2(){
  //This function will run the motors across the range of posibble speeds
  // Note that the maximum speed is determined by the motor itself and operating voltage

  // Turn on motors
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Accelarate from zero to maximum speed
  for(int i=0; i<256;i++){
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(20);
  }
  
  // Decelarate from zero to maximum speed
  for(int i=255; i>=0;--i){
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(20);
  }
  
  //now turn off motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Set Motor A forward
  /*
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set Motor B forward
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Read the values from the potentiometers

  MotorSpeed1 = analogRead(SpeedControl1);
  MotorSpeed2 = analogRead(SpeedControl2);

  // Convert to range of 0-255

  MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
  MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);

  // Adjust to prevent "buzzing" at very low speed

  if (MotorSpeed1 < 8)MotorSpeed1 = 0;

  if (MotorSpeed2 < 8)MotorSpeed2 = 0;

  // Set the motor speed

  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
*/
demo1();

delay(1000);

demo2();

delay(1000);

}
