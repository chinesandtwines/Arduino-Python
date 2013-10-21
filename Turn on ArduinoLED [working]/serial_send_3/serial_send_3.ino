int redLEDpin = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the serial in 19200 baud rate
  pinMode(redLEDpin, OUTPUT);
  Serial.begin(19200); 
  delay(1000);               // wait for a second
  Serial.println("hello");  
}

// the loop routine runs over and over again forever:
void loop() {
  
  if(Serial.available() > 0){
    Serial.println("msg");
    digitalWrite(redLEDpin, HIGH);
        delay(1000);             
        Serial.flush();
  }
}
