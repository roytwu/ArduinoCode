void setup() 
{
  //* open the serial port at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  Serial.print("\nThis is a string\n");

  Serial.print(-1, BIN); //* binary
  Serial.println("\t");
  
  Serial.print(-1, DEC); //* decimal
  Serial.println("\t");
  
  Serial.print(-1, HEX); //* hexadecimal
  Serial.println("\t");

  Serial.print("OCT");
  Serial.println("\t");

  delay(1000); //* delay in milliseconds
  while(1){}   //* infinity loop
}
