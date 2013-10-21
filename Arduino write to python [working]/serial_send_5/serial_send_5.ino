void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    switch(inByte) {
    case 'r': //Data request
      Serial.write('s');
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      break;
    }
    Serial.flush();
  }
}


