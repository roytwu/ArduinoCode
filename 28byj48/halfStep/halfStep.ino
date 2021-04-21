//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: testing stepper motor (28BYJ-48) without built-in library
//* History:     02/18/2021 initial version, modified from "skStepper_noLib"
//*              02/18/2021 half step mode 
//* ===== ===== ===== ===== =====

//* Define Pins & variables
int IN1 = 4; //* driver board to arduino digital pin
int IN2 = 5; 
int IN3 = 6;
int IN4 = 7;
int stepPerRev     = 4096;  //* from data sheet
//int last_step_time = 0; 
//int step_delay     = 100; //*micro-sec
//int steps_left     = 0;
//int step_number    = 0;

/*
stepper motor driving function
*/
void stepMotor(int pin1, int pin2, int pin3, int pin4, long thisStep)
{
   switch (thisStep) 
   {
      case 0:  
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
      break;
      case 1:  
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
      break;
      case 2:  
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
      break;
      case 3:  
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 4:  
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 5:  
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, HIGH);
      break;
      case 6:  
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      case 7:  
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);  
      break;
    }
}


/*
rotate the stepper motor clockwise
    - rev: number of shaft revolution
    - dly: delay between steps
*/
void clockwise (double rev, double dly)
{
  for (int i=0; i<=(rev*stepPerRev); i++) 
  {
    //* be careful to the pin sequence
    stepMotor(IN1, IN2, IN3, IN4, i%8);
    delayMicroseconds(dly*1000);
    //delay(dly);

    //Serial.print(i) ;
    //if ( i==(stepPerRev/2) ){break;}
  }
}

/*
rotate the stepper motor counter-clockwise
    - rev: number of shaft revolution
    - dly: delay between steps
*/
void ccw (double rev, double dly)
{
  for (int i=rev*stepPerRev; i>=0; i--) 
  {
    stepMotor(IN1, IN2, IN3, IN4, i%8);
    delayMicroseconds(dly*1000);
    //delay(dly);

    //Serial.print(i) ;
    //if ( i==(stepPerRev/2) ){break;}
  }  
}


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

//double dly_btw_step  = 2.93;  //* milli-sec up to 3 deical places, 5 rpm
double dly_btw_step  = 0.977;  //* milli-sec, 15 rpm
double rev = 1.0;         //* revolution
//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------   
void loop() 
{
  Serial.print("\nProgram starts...") ;
  
  clockwise(rev, dly_btw_step);
  delay(1000);

  ccw(rev, dly_btw_step);  
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
