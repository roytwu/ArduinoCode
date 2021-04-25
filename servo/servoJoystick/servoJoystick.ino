//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Use joystick y-axis to control a servo motor (SG-90)
//* History:     -04/24/2021 initial version
//* ===== ===== ===== ===== =====

#include <Servo.h> 
int servoPin = 8;
int joyPinX = A0; //* pin for x-dir joystick
int joyPinY = A1; //* pin for y-dir joystick
int offsetX;
Servo myServo; 

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  Serial.begin(9600);
  //myServo.attach(servoPin);          //*(544, 2400) by default
  myServo.attach(servoPin, 520, 2600); //*trial and error
 
  myServo.write(90); //* move to center (joystick neutral)
}

//* 0 - 1023
//* 0 - 1800
//* 0 - 180
//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{   
  int val = analogRead(joyPinY); 
  int deg = map(val, 0, 1023, 0, 180);
  myServo.write(deg);  //* move servo to joystick location
  
  delay(500);
  Serial.println(deg); //* print out degree
} 
