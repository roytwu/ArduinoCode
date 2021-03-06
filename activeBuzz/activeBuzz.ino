//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for active buzzer
//* History:     -03/05/2021 initial version
//* ===== ===== ===== ===== =====
int buzzPin = 6;

void setup()
{
  pinMode(buzzPin,OUTPUT);
}


void loop()
{
 unsigned char i;
 while(1)
 {
   //* output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzPin ,HIGH);
    delay(1);
    digitalWrite(buzPin, LOW);
    delay(1);
    }
    
    //* output another frequency
    for(i=0;i<100;i++)
    {
      digitalWrite(buzPin, HIGH);
      delay(2);
      digitalWrite(buzPin, LOW);
      delay(2);
    }
  }
} 
