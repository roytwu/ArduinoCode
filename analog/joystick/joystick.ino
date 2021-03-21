//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Analog joystick with an active buzzer
//*              Buzzer tone can be adjusted by chaning joystick's position
//*              Buzzer noise can be minimied by pressing the push button on the joystick
//* History:     -05/xx/2020 initial version
//*              -03/21/2021 adding buzzOnOff()
//* ===== ===== ===== ===== =====

const int switchPin = 2; //* joystick  
const int xPin = A0;     //* joystick
const int yPin = A1;     //* joystick
int buzzPin = 8;         //* buzzer


//* toggle viarable for buzzer's pinMode
int pinModeSW = 0;  //* 0: output, 1:input


//* ---------- 
//*     turn buzzer on/off by changing the pinMode
//* ---------- 
void buzzOnOff()
{
  switch (pinModeSW)
  {
    case 0:
      //* current pMode is OUTPUT, swith to INPUT and then break the loop
      //* buzzer shall be quite aftewards
      pinMode(buzzPin, INPUT);
      pinModeSW=1;
      Serial.print(" ");
      Serial.println(pinModeSW);
      break;
    case 1:  
      //* current pMode is INPUT, swith to OUTPUT and break then the loop
      //* buzzer shall be noisy aftewards
      pinMode(buzzPin, OUTPUT);
      pinModeSW=0;
      Serial.print(" ");
      Serial.println(pinModeSW);
      break;
 }
}

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------  
void setup() 
{
  pinMode(buzzPin,  OUTPUT);
  
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  
  Serial.begin(9600);
} 



//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------  
void loop() 
{
  int xValue = analogRead(xPin); //* 0 to 1024
  int yValue = analogRead(yPin); //* 0 to 1024
  int switchV = digitalRead(switchPin); //* high or low
  
  //* print switch value
//  Serial.println(switchV);
//  Serial.print("\n");

  //* ploting x and Y pin together
//  Serial.print(xValue);
//  Serial.print(" ");
//  Serial.println(yValue);

  //* when the push botton is pressed, toggle the buzzer on/off
  if (switchV ==0)
  {
    buzzOnOff();
  }

  int i;
  int counter = 0;
  while(counter < 5)
  {
    //* buzzing in one frequency
    for(i=0; i<80; i++)
    {
      digitalWrite(buzzPin ,HIGH);
      delayMicroseconds(xValue);
      digitalWrite(buzzPin, LOW);
      delayMicroseconds(yValue);
    }
    counter++;   
  } 
  delay(500);
}
