//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Output HC-SR04 measurement to a LCD display
//* History:     -01/22/2021 initial version, modified from a script wrriten by Tom Igoe
//*              -02/13/2021 fixing the overwritten isses with data display   
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
Ultrasonic    o_US(TRIG_PIN, ECHO_PIN);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); //* initialize the LCD library
long dis;

void setup() 
{
  Serial.begin(9600);
 
  lcd.begin(16, 2);    //* set up the LCD's number of columns and rows
  lcd.print("Roy Wu"); //* Print a message
}

void loop() 
{
  dis = o_US.read();          //* distance measurement

  //* -----
  //* preparation
  //* -----
  lcd.setCursor(0, 1);        //* set the cursor to column 0, line 1(2nd row)
  lcd.print(millis() / 1000); //* print number of seconds since reset
  lcd.setCursor(5, 1); 
  lcd.print("Dis:"); 


  //* -----
  //* print out measurement and refresh the display
  //* -----
  lcd.setCursor(9, 1); 
  lcd.print(dis); 
  delay(500);
  lcd.setCursor(9, 1); 
  lcd.print("       "); 


  //* -----
  //* output data to serial monitor
  //* -----
  Serial.print("Distance measurement...");
  Serial.print(dis);
  Serial.println("cm");
}
