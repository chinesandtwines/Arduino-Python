void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); //Red LED w. 220ohm?
  pinMode(3, INPUT); //Hue power button w. 10kohm?
  pinMode(4, OUTPUT); //Green LED
  pinMode(5, OUTPUT); //Blue LED
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    switch(inByte) {
    case 'p': //Data request
      Serial.write('P');
      digitalWrite(2, HIGH);
      delay(250);
      digitalWrite(2, LOW);
      break;
    }
    Serial.flush();
  }
}




