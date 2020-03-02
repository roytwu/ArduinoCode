//* -------------------------
//* Ultrasonic Distance Sensor (HC-SR04)
//* -------------------------
#include <SR04.h>

#define TRIG_PIN 12 //* P12: MISO
#define ECHO_PIN 11 //* P11: MOSI
SR04 oUS = SR04(ECHO_PIN, TRIG_PIN);
long dis;
long avgDis;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   dis = oUS.Distance();
   avgDis = oUS.DistanceAvg(10,50);
   Serial.print("current distance...");
   Serial.print(dis);
   Serial.println("cm");

   Serial.print("avg distance...");
   Serial.print(avgDis);
   Serial.println("cm");
   Serial.println("\n\n\n\n");
   delay(1000);
}
