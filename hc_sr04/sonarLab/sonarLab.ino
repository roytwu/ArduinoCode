//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Compare raw measurement and built-in libraries
//* History:     -02/20/2021 initial version, modified from "sonarAndLCD"
//*               
//* ===== ===== ===== ===== =====
/*
 Demonstrates the use a 16x2 LCD display.  
 The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver. 
 There are many of them out there, and one can usually tell them by the 16-pin interface.
 
 The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 11
 * LCD D6 pin to digital pin 12
 * LCD D7 pin to digital pin 13
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VDD pin to 5V
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h> //* use library manager
#include <Ultrasonic.h>    //* use library manager

#define TRIG_PIN 2      //* UNO output
#define ECHO_PIN 3      //* UNO input
#define pulseTimeout  100000  //* 100 milli-sec
Ultrasonic    o_US(TRIG_PIN, ECHO_PIN);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); //* initialize the LCD library
long duration;
long distLib;  //* distance from library output
long distTOF;  //* distance from usMeasure()

long usMeasure()
{
  //* create a trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //* ----- -----
  //*   sensor exposure: 
  //*   starts timing when echoPin go from LOW to HIGH, 
  //*   and then stop timing when echPin go back to LOW
  //* ----- -----
  duration = pulseIn(ECHO_PIN, HIGH, pulseTimeout);

  //* time of flight: micro-sec to centimeter
  long dist_cm = 0.5*(duration*343*100)/1000000;
  return dist_cm;
}


void setup() 
{
  Serial.begin(9600);
 
  lcd.begin(16, 2);    //* set up the LCD's number of columns and rows
  lcd.setCursor(0, 0); 
  lcd.print("raw:"); 
  
  lcd.setCursor(10, 0); 
  lcd.print("Roy Wu"); //* Print a message
  
  lcd.setCursor(0, 1); 
  lcd.print("lib:"); 
}

void loop() 
{
  distLib = o_US.read();          //* distance measurement
  distTOF = usMeasure();

  //* -----
  //* preparation
  //* -----
  lcd.setCursor(10, 1);        //* set the cursor to column 0, line 1(2nd row)
  lcd.print(millis() / 1000); //* print number of seconds since reset


  //* -----
  //* print out measurement and refresh the display
  //* -----
  lcd.setCursor(4, 0); 
  lcd.print(distTOF); 
   lcd.setCursor(4, 1); 
  lcd.print(distLib); 
  delay(500);
  lcd.setCursor(4, 0); 
  lcd.print("     "); 
  lcd.setCursor(4, 1); 
  lcd.print("     "); 




  //* -----
  //* output data to serial monitor
  //* -----
  Serial.print("Distance measurement...");
  Serial.print(distLib);
  Serial.println("cm");
}
