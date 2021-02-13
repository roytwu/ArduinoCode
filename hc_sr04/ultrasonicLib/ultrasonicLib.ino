//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Testing the ultrasonic library created by Eric Simoes (ver. 3.0.0)
//*              https://github.com/ErickSimoes/Ultrasonic
//* History:     -02/13/2021, initial version
//* ===== ===== ===== ===== =====

#include <Ultrasonic.h> //* the library must be installed in advance
#define TRIG_PIN 2      //* UNO output
#define ECHO_PIN 3      //* UNO input

//* declare a object named "o_US" under the "Ultrasonic" class
Ultrasonic o_US(TRIG_PIN, ECHO_PIN);
long dis;


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
   //* call the member function in the class
   dis = o_US.read();
   Serial.print("current measurement...");
   Serial.print(dis);
   Serial.println("cm");

   //* now open the Serial Monitor from [Tools] to see the measurement output 

}
