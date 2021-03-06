//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Compare raw measurement and built-in libraries
//* History:     -02/20/2021 initial version, modified from "sonarAndLCD"
//*              -03/05/2021 add buzzer
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
#include <Ultrasonic.h>    //* primitive library for HC-SR04
#include <NewPing.h>       //* a much better library for HC-SR04

#define trigPin 2      //* UNO output
#define echoPin 3      //* UNO input
#define buzzPin 6     //* active buzzer pin
#define pulseTimeout  100000  //* 100 milli-sec

LiquidCrystal lcd(8, 9, 10, 11, 12, 13); //* initialize the LCD library
long duration;
long dist;  

long usMeasure()
{
  //* create a trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //* ----- -----
  //*   sensor exposure: 
  //*   starts timing when echoPin go from LOW to HIGH, 
  //*   and then stop timing when echPin go back to LOW
  //* ----- -----
  duration = pulseIn(echoPin, HIGH, pulseTimeout);

  //* time of flight: micro-sec to centimeter
  long dist_cm = 0.5*(duration*343*100)/1000000;
  return dist_cm;
}

void makingNoise(int dly_micro)
{
  int count=0;
  while(count<5)
  {
    for(int i=0; i<60; i++)
    {
      digitalWrite(buzzPin, HIGH);
      delayMicroseconds(dly_micro);
      digitalWrite(buzzPin, LOW);
      delayMicroseconds(dly_micro);
    }
    count++;
  }
}  


//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------   
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin,  OUTPUT);
 
  lcd.begin(16, 2);    //* set up the LCD's number of columns and rows
  lcd.setCursor(10, 0); 
  lcd.print("Roy Wu"); //* Print a message
  
  lcd.setCursor(0, 1); 
  lcd.print("dist:"); 
}

//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------   
void loop() 
{
  //* distance measurement
  dist = usMeasure();
  
  //* -----
  //* different buzzing tone
  //* -----
  if (dist >=60)
  {
    makingNoise(3000);
  }
  else if (dist>=40 && dist<60)
  {
    makingNoise(2000);
  }
  else if(dist>=20 && dist <40)
  {
    makingNoise(1000);
  } 
  else if(dist<20)
  {
    makingNoise(500);
  }
  

  //* -----
  //* LCD preparation
  //* -----
  lcd.setCursor(10, 1);       //* set the cursor to column 0, line 1(2nd row)
  lcd.print(millis() / 1000); //* print number of seconds since reset


  //* -----
  //* print out measurement and refresh the display
  //* -----
  lcd.setCursor(5, 1); 
  lcd.print(dist); 
  delay(500);
  lcd.setCursor(5, 1); 
  lcd.print("     "); 



  //* -----
  //* output data to serial monitor
  //* -----
  Serial.print("Distance measurement...");
  Serial.print(dist);
  Serial.println("cm");
}
