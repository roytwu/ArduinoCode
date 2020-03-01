//* -----------------------------------
//* turn on multiple LEDs with for loop
//* -----------------------------------
int ledPins[] = {8, 9, 10};  
int numPin =3;

void setup() {
  //* open the serial port at 9600 bps:
    Serial.begin(9600);

  for (int thisPin = 0; thisPin < numPin; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
  for (int thisPin = 0; thisPin < numPin; thisPin++) {
    //* turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    
    int timer = 300; 
    delay(timer);
    
    //* turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
