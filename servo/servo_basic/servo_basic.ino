//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

#include <Servo.h> 
int servoPin = 8;
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
//   //* Make servo go to 90 degrees 
//   Servo1.write(90); 
//   delay(500); 
//   
//   //* Make servo go to 180 degrees 
//   Servo1.write(180); 
//   delay(500); 
//
//   //* Make servo go to 180 degrees 
//   Servo1.write(90); 
//   delay(500); 
//
//   //* Make servo go to 180 degrees 
//   Servo1.write(0); 
//   delay(2000); 


  //* scan from 0 to 180 degrees
  for(int angle = 10; angle < 180; angle++)  
  {                                  
    Servo1.write(angle);               
    delay(15);                   
  } 
  delay(500); 
  //* now scan back from 180 to 0 degrees
  for(int angle = 180; angle > 10; angle--)    
  {                                
    Servo1.write(angle);           
    delay(15);       
  } 
  delay(500); 
   
} 
