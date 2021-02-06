//* ----- ----- ----- ----- -----
//* Author:      Roy Wu
//* Description: reading IMU data from Nano 33 BLE Sense
//* History:     02/06/2022 initial version, accelerometer data only

//* Workflow:    step1: upload this sketch to PC
//*              step2: open serial monitor and make sure data is printing out correctly
//*              step3: close the serial monitor   
//*              step4: open serialCommTest.py and run it
//* ----- ----- ----- ----- -----

//* Nano33BLE has a onbard IMU, LSM9DS1
#include <Arduino_LSM9DS1.h>

//float x, y, z, delta = 0.05;


//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------   
void setup() 
{
  //Serial.begin(9600);
  Serial.begin(38400);

  if (!IMU.begin()) 
  {
    Serial.println("Failed to initialize IMU...");
    while (1);
  }
}

//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------   
void loop() 
{
  float x, y, z;
  if (IMU.accelerationAvailable()) 
    {
      IMU.readAcceleration(x, y, z);
      Serial.print(x, 4);
      Serial.print(", ");
      Serial.print(y, 4);
      Serial.print(", ");
      Serial.println(z, 4); //* must use EOL for the last data point
    }

//    //Serial.print("Accelerometer sample rate = ");
//    Serial.print(IMU.accelerationSampleRate(),4);
//    Serial.print(", ");
//    Serial.println(IMU.accelerationSampleRate()+1,4);

//    //* ----- ----- -----
//    //* small testing function
//    //* ----- ----- -----
//    if (IMU.accelerationAvailable())
//    {
//      IMU.readAcceleration(x, y, z);
// 
//      if(y <= delta && y >= -delta)
//      {
//        Serial.println("flat");
//      } 
//      else if(y > delta && y < 1 - delta)
//      {
//        Serial.println("left tilting");
//      }
//      else if(y >= 1 - delta) 
//      {
//          Serial.println("left (trans)");
//      }    
//      else if(y < -delta && y > delta - 1)
//      {
//          Serial.println("right tilting");
//      }
//      else 
//      {
//          Serial.println("right (trans)");   
//       }
//    }    



}
