void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); //Red LED
  pinMode(4, OUTPUT); //Green LED
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    switch(inByte) {
    case 'r': //Flash red LED
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      Serial.write('R');
      break;
    case 'g': //Flash green LED
      digitalWrite(4, HIGH);
      delay(1000);
      digitalWrite(4, LOW);
      Serial.write('G');
      break;
    }
    Serial.flush();
  }
}


