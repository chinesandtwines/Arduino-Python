int redLEDpin = 2;
int incomingByte = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the serial in 19200 baud rate
  pinMode(redLEDpin, OUTPUT);
  Serial.begin(19200); 
  //delay(1000);               // wait for a second
  //Serial.println("hello");  
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.write(45);
}
