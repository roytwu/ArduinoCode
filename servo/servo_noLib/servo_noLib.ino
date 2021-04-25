//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: basic program for servo motor
//* History:     -04/21/2021 initial version
//* ===== ===== ===== ===== =====

int servoPin = 10;

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
  
  for(int i=0; i<100; i++)
  {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(1900);    //position
    digitalWrite(servoPin, LOW);
    delayMicroseconds(18100);   //balance of 20000 cycle
  }

  delay(2000);
  
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(1100);    //position
  digitalWrite(servoPin, LOW);
  delayMicroseconds(18900);   //balance of 20000 cycle
} 
