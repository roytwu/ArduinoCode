//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for active buzzer
//*              buzzer would humning in two different tone 3 times in one cycle
//*              adjusting the delay time to tune the himming tone
//* History:     -03/05/2021 initial version
//* ===== ===== ===== ===== =====
int buzzPin = 7;


//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  pinMode(buzzPin, OUTPUT);
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{
 int i;
 int counter = 0;
 while(counter < 3)
 {
//   //* buzzing in one frequency
//   for(i=0; i<80; i++)
//   {
//    digitalWrite(buzzPin ,HIGH);
//    delay(1);
//    digitalWrite(buzzPin, LOW);
//    delay(1);
//   }
    
   //* buzzing in another frequency
//   for(i=0; i<100; i++)
//   {
//     digitalWrite(buzzPin, HIGH);
//     delay(100);
//     digitalWrite(buzzPin, LOW);
//     delay(100);
//   }
   for(i=0; i<100; i++)
   {
     analogWrite(buzzPin, 200);
     delay(100);
     analogWrite(buzzPin, 0);
     delay(100);
   }
    
    
  counter++;  
  }

  //* after buzzing 3 cycles, take a 2.5 sec break
  digitalWrite(buzzPin, LOW);
  delay(2500);
} 
