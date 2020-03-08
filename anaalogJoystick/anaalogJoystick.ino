//* ****************************
//*　Author:      Roy Wu
//*　Description: Read analog joystick
//* ****************************

//* Arduino pin numbers
const int switchPin = 11; //* digital pin connected to switch output
const int xPin = A4;      //* analog pin connected to X output
const int yPin = A5;      //* analog pin connected to Y output

void setup() 
{
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() 
{
  int xValue = analogRead(xPin); //* 0-1024
  int yValue = analogRead(yPin); //* 0-1024
  int switchV = digitalRead(switchPin);//* high & low
  
  //Serial.print("Switch:  ");
  //Serial.print(switchV);
  //Serial.print("\n");
  
  //Serial.print("X-axis: ");
  //Serial.println(analogRead(X_pin));
  //Serial.print("\n");

  //* print X&Y separately
  //Serial.println(xValue);
  //Serial.print("\n\n");

  //* ploting x and Y pin together
  Serial.print(xValue);
  Serial.print(" ");
  Serial.println(yValue);

  int sec = 1.0;
  delay(sec*100);
}
