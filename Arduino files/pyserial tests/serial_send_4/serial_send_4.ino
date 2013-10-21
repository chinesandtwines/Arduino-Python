void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  // write something over serial so python knows we're ready
  Serial.write('1'); 
}

void loop() {
  if(Serial.available() > 0) { // if data present, blink
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    Serial.write('0');
    //Serial.flush();
  }
}
