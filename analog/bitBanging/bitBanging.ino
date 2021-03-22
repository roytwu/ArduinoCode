//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: bit-banging
//* History:     -04/xx/2020 initial version
//* ===== ===== ===== ===== =====
int buzzPin = 5;

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
  //* Beeping every 0.5 sec
  //* ----- ----- ----- -----
//  digitalWrite(buzzPin, HIGH); 
//  delay(0.5*1000);             
//  digitalWrite(buzzPin, LOW);  
//  delay(0.5*1000);             

  //* ----- ----- ----- -----
  //* adjusting volume with analogWrite
  //* pin 3, 5, 6, 9, 10, 11
  //* ----- ----- ----- -----
//  analogWrite(buzzPin, 150); //* 0 - 255
//  delay(0.5*1000);
//  analogWrite(buzzPin, 10); //* 0 - 255
//  delay(0.5*1000);


  //* ----- ----- ----- -----
  //* bit banging
  //* one can bang all the digital pins
  //* Approximately dc/10% duty cycle @ 1KHz
  //* ----- ----- ----- -----  
  int dc=100; //* duty cycle
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(dc);     
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(2000 - dc);
  

//  int sec =0.5;
//  delay(sec*1000);
}
