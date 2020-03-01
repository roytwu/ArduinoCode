//* ------------------------------------
//* Basic operations about integer arrays
//* ------------------------------------
int arr[10];


void setup() 
{
    //* open the serial port at 9600 bps:
    Serial.begin(9600);
}

void loop() 
{
  int len = sizeof(arr)/sizeof(arr[0]);
  Serial.print("\nlegnth of Array is...") ;
  Serial.print(len) ;  
  for (int i=0; i<len; i++ )
  {
    arr[i] = i*10; 
  }  
  
  Serial.print("\nPrint array data...\n") ; 
  printArray(arr, len);

  Serial.print("\n\n\n\n\n");
  int sec=3;
  delay(sec*1000);
}


void printArray(int n[], int len)
{
   for ( int i = 0; i < len; ++i )
   {
      int output = n[i];
      Serial.print(output) ;
      Serial.print("\n") ;
   }   
}
