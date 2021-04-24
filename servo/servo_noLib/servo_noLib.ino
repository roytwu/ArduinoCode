//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

int servoPin = 8;

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup()
{
  Serial.begin(9600);
  Serial.println("poor man's servo sweep");
  
  pinMode(servoPin, OUTPUT);
  digitalWrite(servoPin, LOW);
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop()
{
  Serial.print("one side...");
  

  int timeHigh = 1500;
  int timeLow  = 20000-timeHigh;
  for (int i=0; i<50; i++)
  {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(timeHigh);       //90 degree
    digitalWrite(servoPin, LOW);
    delayMicroseconds(timeLow); //balance of 20000 cycle
  }
  delay(1000);
  
  
} 
