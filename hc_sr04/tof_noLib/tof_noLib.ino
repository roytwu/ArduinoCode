//* ===== ===== ===== ===== =====
//* Author:      Roy Wu
//* Description: Test HC-SR04 without using a library
//* History:     -02/20/2021 initial version
//*               
//* ===== ===== ===== ===== =====
#define trigPin 2      //* UNO output
#define echoPin 3      //* UNO input

double duration;
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
  Serial.println("program starts...");
  
  //* create a trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //* starts timing when echoPin go from LOW to HIGH
  //* stop timing when echPin go from HIH back to LOW
  duration = pulseIn(echoPin, HIGH);

  //* micro-sec to centimeter
  dist_cm = (duration* 100)/5882;
  
  Serial.print("distance is... ");
  Serial.print(duration);
  //Serial.println(dist_cm);
}
