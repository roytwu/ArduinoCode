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
float accX, accY, accZ;
float gyX, gyY, gyZ;

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
  //* sending raw dat over
  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) 
    {
      IMU.readAcceleration(accX, accY, accZ);
      IMU.readGyroscope(gyX, gyY, gyZ);
      
      Serial.print(accX, 4);
      Serial.print(", ");
      Serial.print(accY, 4);
      Serial.print(", ");
      Serial.print(accZ, 4); 
      Serial.print(", ");
      Serial.print(gyX, 4);
      Serial.print(", ");
      Serial.print(gyY, 4);
      Serial.print(", ");
      Serial.println(gyZ, 4); //* must use EOL for the last data point
    }

}
