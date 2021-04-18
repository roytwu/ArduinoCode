//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: bit-banging
//* History:     -04/xx/2020 initial version
//* ===== ===== ===== ===== =====
int buzzPin = 7;

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup() 
{
  Serial.begin(9600);       //* open the serial port at 9600 bps:
  pinMode(buzzPin, OUTPUT); //* Declaring buzzer pin as output
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop() 
{  
  //* ----- ----- ----- -----
  //* adjusting volume with analogWrite
  //* pin 3, 5, 6, 9, 10, 11
  //* ----- ----- ----- -----
  analogWrite(buzzPin, 220); //* 0 - 255
  delay(500);
  analogWrite(buzzPin, 120); //* 0 - 255
  delay(500);
  analogWrite(buzzPin, 10); //* 0 - 255
  delay(500);


  //* ----- ----- ----- -----
  //* adjusting volume with analogWrite
  //* pin 3, 5, 6, 9, 10, 11
  //* ----- ----- ----- -----
//  int i;
//  int counter = 0;
//  while(counter < 3)
//  {
//    //* buzzing in one frequency
//    for(i=0; i<80; i++)
//    {
//      analogWrite(buzzPin, 255); //* full volume: 255
//      delay(1);
//      analogWrite(buzzPin, 0);
//      delay(1);
//    }     
//    counter++;  
//  }


  //* ----- ----- ----- -----
  //* bit banging
  //* one can bang all the digital pins
  //* Approximately dc/10% duty cycle @ 1KHz
  //* ----- ----- ----- -----  
//  int dc=2000; //* duty cycle
//  digitalWrite(buzzPin, HIGH);
//  delayMicroseconds(dc);     
//  digitalWrite(buzzPin, LOW);
//  //delayMicroseconds(2000 - dc);
//  delayMicroseconds(16000 - dc);
//
//  delay(1);
//  digitalWrite(buzzPin, LOW);

  
  delay(2000);
}
