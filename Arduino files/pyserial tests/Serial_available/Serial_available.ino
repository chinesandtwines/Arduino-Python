void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);

}

void loop() {
  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial2.print(inByte, BYTE); 

  }
  // read from port 1, send to port 0:
  if (Serial2.available()) {
    int inByte = Serial1.read();
    Serial.print(inByte, BYTE); 
  }
}
