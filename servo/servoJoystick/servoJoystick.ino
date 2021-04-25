//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

#include <Servo.h> 
int servoPin = 8;
int joyPinX = A0; //* pin for x-dir joystick
int joyPiny = A1; //* pin for y-dir joystick
int offsetX;
Servo myServo; 

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  Serial.begin(9600);
  //myServo.attach(servoPin);
  myServo.attach(servoPin, 1000, 2000);
 
  myServo.write(90); //* move to center (joystick neutral)
  offsetX = analogRead(joyPinX); //* initial joystick x-val
//  offsetY = analogRead(joyPinY); //* initial joystick y-val
}

//* 0 - 1023
//* 0 - 1800
//* 0 - 180
//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{   
  int xVal = analogRead(joyPinX)-512; 
  int deg = round(xVal*180/1023);
  myServo.write(deg);  //* move servo to joystick location
  delay(500);
  Serial.println(joyPinX); //* print out degree
} 
