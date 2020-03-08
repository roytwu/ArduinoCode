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
  //* ----- ----- ----- -----
  //* Beeping every 0.5 sec
  //* ----- ----- ----- -----
//  digitalWrite(buzzPin, HIGH); //* buzzer on!!!
//  delay(0.5*1000);             //* wait
//  digitalWrite(buzzPin, LOW);  //* buzzer off..
//  delay(0.5*1000);             //* wait  


  //* ----- ----- ----- -----
  //* adjusting volume with analogWrite
  //* only every digital pins can do this
  //* ----- ----- ----- -----
//  analogWrite(buzzPin, 30); //* 0 - 255
//  delay(0.5*1000);
//  analogWrite(buzzPin, 10); //* 0 - 255
//  delay(0.5*1000);


  //* ----- ----- ----- -----
  //* bit banging
  //* you can ban all the digital pins
  //* Approximately dc/10% duty cycle @ 1KHz
  //* ----- ----- ----- -----  
  int dc=800; //* duty cycle
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(dc);     
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(2000 - dc);
  

//  int sec =0.5;
//  delay(sec*1000);
}
//* ------------------------------
