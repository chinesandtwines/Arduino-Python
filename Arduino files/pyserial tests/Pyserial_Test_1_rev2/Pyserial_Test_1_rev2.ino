int LEDstate = 0;
int switchState = 0;
int trigger = 0;
int incomingByte = 0; // for incoming serial data

void setup() {
  pinMode(2, OUTPUT); // Red LED
  pinMode(3, INPUT); // Button
  pinMode(4, OUTPUT); // Green LED
  pinMode(5, OUTPUT); // Blue LED
  Serial.begin(9600);
  
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
}

void loop() {
  switchState = digitalRead(3);
  
  if (Serial.available() > 0) {
    digitalWrite(4, HIGH); // Turn on Green LED
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(5, HIGH);
    delay(250);
 
  }
  else {
    digitalWrite(2, HIGH); // Turn on Red LED
  }
}
