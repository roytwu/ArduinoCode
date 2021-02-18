//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: testing stepper motor (28BYJ-48) without built-in library
//* History:     02/18/2021 initial version
//* ===== ===== ===== ===== =====

void stepMotor(int pin1, int pin2, int pin3, int pin4, int thisStep)
{
   switch (thisStep) 
   {
      case 0:  //* 1010
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 1:  //* 0110
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 2:  //* 0101
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
      case 3:  //* 1001
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
    }
}


//* Define Pins & variables
int IN1 = 4; //* driver board to arduino digital pin
int IN2 = 5; 
int IN3 = 6;
int IN4 = 7;
int last_step_time = 0; 
int step_delay     = 100; //*micro-sec
int steps_left     = 0;
int stepPerRev     = 4096;  //* from data sheet
int step_number    = 0;

double dly_btw_step  = 3;  //* milli-sec
double rev = 0.5;        //* revolution

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------   
void setup() 
{
    Serial.begin(9600); 
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------   
void loop() 
{
  Serial.print("\nProgram starts...") ;
  //Serial.print(interval) ; 
  
  for (int i=0; i<=(rev*stepPerRev*0.5); i++) 
  {
    //* be careful to the pin sequence
    stepMotor(IN1, IN3, IN2, IN4, i%4);
    //delayMicroseconds(dly_btw_step*1000);
    delay(dly_btw_step);

    //Serial.print(i) ;
    //if ( i==(stepPerRev/2) ){break;}
  }
  delay(1000);

//  while (steps_left > 0)
//  {
//    unsigned long now = micros();
//    
//    //* ----- ----- ----- ----- -----
//    //*     move only if the appropriate delay has passed
//    //* ----- ----- ----- ----- -----
//    if (now - last_step_time >= step_delay)
//    {
//      last_step_time = now; //* get the timeStamp of when you stepped
//      step_number++;
//      if (step_number == number_of_steps) 
//      {
//        step_number = 0;
//      }
//
//      //* decrement the steps left:
//      steps_left--;
//      
//      //* step the motor to step number 0, 1, ..., {3 or 10}
//      stepMotor(8, 9, 10, 11, step_number % 4);
//    }
//  }


}
