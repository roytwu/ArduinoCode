//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Test HC-SR04 without using a library
//* History:     -02/20/2021 initial version
//*               
//* ===== ===== ===== ===== =====
#define trigPin 2      //* UNO output
#define echoPin 3      //* UNO input
#define pulseTimeout  100000  //* 100 milli-sec

long duration;
long dist_cm;  //* distance in centimeter

//* ---------- ---------- ----------
//*     standard Arduino setup
//* ---------- ---------- ----------   
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


//* ---------- ---------- ----------
//*     standard Arduino loop
//* ---------- ---------- ----------   
void loop() 
{ 
  //* ----- -----
  //*   create a trigger pulse
  //* ----- -----
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //* ----- -----
  //*   sensor exposure: 
  //*   starts timing when echoPin go from LOW to HIGH, 
  //*   and then stop timing when echPin go back to LOW
  //* ----- -----
  duration = pulseIn(echoPin, HIGH, pulseTimeout);

  //* ----- -----
  //*   time of flight: micro-sec to centimeter
  //* ----- -----
  dist_cm = 0.5*(duration*343*100)/1000000;
  
  Serial.print("distance is... ");
  Serial.println(dist_cm);
}
