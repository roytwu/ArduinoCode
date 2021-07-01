//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for active buzzer
//*              buzzer would humning in two different tone 3 times in one cycle
//*              adjusting the delay time to tune the himming tone
//* History:     -03/05/2021 initial version
//* ===== ===== ===== ===== =====
int buzzPin = 6;

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
    digitalWrite(buzzPin ,HIGH);
    delay(500);
    digitalWrite(buzzPin, LOW);
    delay(500);
}
