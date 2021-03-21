//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Read analog joystick
//* History:     -05/xx/2020 initial version
//* ===== ===== ===== ===== =====


const int switchPin = 2;  //* switch output
const int xPin = A0;      //* X output
const int yPin = A1;      //* Y output



//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup() 
{
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  
  Serial.begin(9600);
} 



//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop() 
{
  int xValue = analogRead(xPin); //* 0 to 1024
  int yValue = analogRead(yPin); //* 0 to 1024
  int switchV = digitalRead(switchPin);//* high & low
  
  //* print switch value
//  Serial.println(switchV);
//  Serial.print("\n");

  //* print X&Y separately
//  Serial.println(xValue);
//  Serial.print("\n\n");

  //* ploting x and Y pin together
  Serial.print(xValue);
  Serial.print(" ");
  Serial.println(yValue);

  int sec = 1.0;
  delay(sec*1000);
}
