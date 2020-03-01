void setup() 
{
  //* open the serial port at 9600 bps:
  Serial.begin(9600);
}

void loop() 
{
  long curTime = millis();
  //Serial.print("\nCurrent time step...");
  //Serial.print(curTime);
  
//  double sigA = 2*sin(curTime/40);
//  double sigB = 2*cos(curTime/40);
//  Serial.print(sigA);
//  Serial.print(" ");
//  Serial.println(sigB);

  while(1)
  {
    for(int i=0; i<360; i++)
    {
      double sigC = 2*sin(i*PI/180);
      double sigD = 3*cos((i*PI/180)-PI/2);
      //double sigD = 3*cos(i*PI/180);
      Serial.print(sigC);
      Serial.print(" ");
      Serial.println(sigD);

    }
  }

  //int sec =1;
  //delay(2*1000);

}
