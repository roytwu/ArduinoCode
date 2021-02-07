//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Testing script program for Ultrasonic Distance Sensor (HC-SR04)
//* History:     -??/??/2020, initial version
//*              -02/07/2021, project revivial, minor update  
//* ===== ===== ===== ===== =====
#include <SR04.h>    //* 3rd party library

#define TRIG_PIN 7  //* UNO output
#define ECHO_PIN 6  //* UNO input

SR04 oUS = SR04(ECHO_PIN, TRIG_PIN);
long dis;
long avgDis;

//* ---------- ----------
//*     standard Arduino setup
//* ---------- ----------
void setup() 
{
   Serial.begin(9600);
   delay(1000);
}



//* ---------- ----------
//*     standard Arduino loop
//* ---------- ----------
void loop() 
{
   dis = oUS.Distance();
   //avgDis = oUS.DistanceAvg(10,50);
   Serial.print("current distance...");
   Serial.print(dis);
   Serial.println("cm");

   //Serial.print("avg distance...");
   //Serial.print(avgDis);
   //Serial.println("cm");
   //Serial.println("\n\n\n\n");
   //delay(1000);
}
