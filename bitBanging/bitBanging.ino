//* ****************************************
//* Author:      Roy Wu
//* Description: Bit-banging
//* ****************************************
int buzzPin = 5;

//* ------------------------------
void setup() 
{
  Serial.begin(9600);       //* open the serial port at 9600 bps:
  pinMode(buzzPin, OUTPUT); //* Declaring buzzer pin as output
}
//* ------------------------------

//* ------------------------------
void loop() 
{  
  //* Beeping every 0.5 sec
//  digitalWrite(buzzPin, HIGH); //* buzzer on!!!
//  delay(0.5*1000);             //* wait
//  digitalWrite(buzzPin, LOW);  //* buzzer off..
//  delay(0.5*1000);             //* wait  

  //* bit banging
  int dc=300; //* duty cycle
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(dc);     //* Approximately 10% duty cycle @ 1KHz  
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(1000 - dc);
//  delay(500);
  

//  int sec =0.5;
//  delay(sec*1000);
}
//* ------------------------------
