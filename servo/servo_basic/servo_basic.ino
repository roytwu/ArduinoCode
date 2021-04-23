//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

#include <Servo.h> 
int servoPin = 10;
Servo Servo1; 

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  Serial.begin(9600);
  Serial.println("poor man's servo sweep");
  
  Servo1.attach(servoPin); 
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(1000); 
   
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
} 
