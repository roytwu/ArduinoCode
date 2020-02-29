//* Demonstrating Modulo Arithmetic 
//* with Arduino UNO basic data types 

#define BYTE

#ifdef BYTE
 byte var = pow(2, 8)-3; //* 1 byte
#endif

#ifdef INT
 int var = pow(2, 15)-1;  //* 2 byte
#endif 

#ifdef UINT
 unsigned int var = pow(2, 16)-2; 
#endif


void setup() 
{
  //* open the serial port at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  Serial.print("\n---------------------");
  Serial.print("\nSerial Comm starts...\n");
  Serial.print("---------------------\n");
//  Serial.print(too, BIN); //* binary
//  Serial.println("\t");
//  Serial.print(too, DEC); //* decimal
//  Serial.println("\t");
//  Serial.print(too, HEX); //* hexadecimal
//  Serial.println("\t");

  printVar();

  int sec = 4;
  delay(sec*1000); //* delay in milliseconds
  //while(1){}   //* infinity loop
}

void printVar()
{
  int sizeVar = sizeof(var);
  Serial.print("size of var is... ");
  Serial.print(sizeVar);
  Serial.print("\nDecimal value of var is... ");
  Serial.print(var);
  Serial.print("\nBinary value of var is...  ");
  Serial.print(var, BIN);
  Serial.print("\nHex value of var is...     ");
  Serial.print(var, HEX);

  var = var +1;
  Serial.print("\n\nUpdated decimal value of var is... ");
  Serial.print(var);
  Serial.print("\nUpated binary value of var is...     ");
  Serial.print(var, BIN);
  Serial.print("\nUpdated hex value of new var is...   ");
  Serial.print(var, HEX);
  Serial.print("\n\n\n\n\n\n\n");
}
