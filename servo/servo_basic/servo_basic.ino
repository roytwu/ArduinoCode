//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

#include <Servo.h> 
int servoPin = 8;
Servo myServo; 

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  Serial.begin(9600);
  Serial.println("poor man's servo sweep");
  
  myServo.attach(servoPin); 
  myServo.attach(servoPin, 500, 2600); 
  //myServo.attach(servoPin, 540, 700); 
  //myServo.writeMicroseconds(300);  
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{   
   //* Make servo go to 90 degrees 
   //myServo.write(90); 
   myServo.writeMicroseconds(1200);  
   delay(500); 
   
   //* Make servo go to 180 degrees 
   //myServo.write(180); 
   myServo.writeMicroseconds(2600);  
   delay(500); 

   myServo.writeMicroseconds(1200);  
   delay(500); 

   //* Make servo go to 180 degrees 
   //myServo.write(90); 
   myServo.writeMicroseconds(600);  
   delay(500); 

   //* Make servo go to 180 degrees 
   //myServo.write(0); 
   myServo.writeMicroseconds(500);  
   delay(500); 


//  //* scan from 0 to 180 degrees
//  for(int angle = 10; angle < 180; angle++)  
//  {                                  
//    myServo.write(angle);               
//    delay(15);                   
//  } 
//  delay(500); 
//  //* now scan back from 180 to 0 degrees
//  for(int angle = 180; angle > 10; angle--)    
//  {                                
//    myServo.write(angle);           
//    delay(15);       
//  } 
//  delay(500); 
   
} 
