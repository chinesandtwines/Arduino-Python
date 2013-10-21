int LEDstate = 0;
int switchState = 0;
int trigger = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  switchState = digitalRead(3);
  
  if (switchState == HIGH && LEDstate == 0) {
    trigger = 1;
  }
  else if (switchState == HIGH && LEDstate == 1) {
    trigger = 0;
  }
  
  if (trigger == 1) {
    digitalWrite(2, HIGH);
    LEDstate = 1;
    delay(250);
  }
  else if (trigger == 0) {
    digitalWrite(2, LOW);
    LEDstate = 0;
    delay(250);
  }
}
