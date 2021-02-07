//* ----- ----- ----- ----- -----
//* Author:      Roy Wu
//* Description: randomly light up the LEDs
//* History:     01/22/2021 initial version
//* Tinkercad:   https://www.tinkercad.com/things/5O9RS3cB9r8
//* ----- ----- ----- ----- -----

//* Define Pins & variables
const int anlgPin = A5;
long randNum;
int  inputVal = 0;

//* ---------- ----------
//*     blinking function (analog)
//* ---------- ----------

//* blink 1 LED with analog value
void blink(int ledPin, int value)
{
  analogWrite(ledPin, value);
  delay(100); //* millisecond(s)
  
  analogWrite(ledPin, 0);
  delay(100); // millisecond(s)
}

//* blink 2 LEDs at the same time with analog value
void blink_2(int ledPin1, int ledPin2, int value)
{
  analogWrite(ledPin1, value);
  analogWrite(ledPin2, value);
  delay(100); //* millisecond(s)
  
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  delay(100); // millisecond(s)
}

//* blink 8 LEDs at the same time with analog value
void blink_8(int value)
{
  for (int i=0; i<=7; i++)
  {
    analogWrite(i+2, value);
  }
  delay(200); //* millisecond(s)
  
  for (int i=0; i<=7; i++)
  {
    analogWrite(i+2, 0);
  }
  delay(100); // millisecond(s)
}


//* center to edge, edge to center (two times)
void patternB(int counter, int value)
{
  int i=0;
  while (i<=counter)
  {
    for (int i=0; i<=3; i++)
    {     
      blink_2(i+6, 5-i, value);
    }
  
    for (int i=3; i>0; i--)
    {
      blink_2(i+6, 5-i, value);
    }
    i++;
  }
}




//* ---------- ----------
//*     standard Arduino setup
//* ---------- ----------
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  //* make sure all LED is off
  for (int i=0; i<=7; i++)
  {
    digitalWrite(i+2, LOW);
  }
}


void loop()
{
  inputVal = analogRead(anlgPin);
  Serial.println(inputVal);
  
  randNum = random(3);//* 0, 1, 2
  switch (randNum) 
  {
    case 0:
      //* pattern A (forward and then backward)
      for (int i=2; i<=9; i++)
      {
        blink(i, inputVal);
      }
      for (int i=9; i>=2; i--)
      {
        blink(i, inputVal);
      }
      break;
    case 1:
      //* pattern B
      patternB(2, inputVal); 
      break;
    case 2:
      //* pattern C
      blink_8(inputVal);
      blink_8(inputVal);
      blink_8(inputVal);
      blink_8(inputVal);
      break;
  }
}
