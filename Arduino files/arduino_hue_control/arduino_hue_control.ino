#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char inData[16];
int index;
boolean started = false;
boolean ended = false;
char firstchar;

void setup() {
  pinMode(7, OUTPUT); //Red LED
  pinMode(6, INPUT); //LED power toggle button
  pinMode(13, INPUT); //LED red
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("init done");
  delay(1000);
  lcd.clear();
}

void loop() {
  while(Serial.available() > 0) {
    if (digitalRead(6) == HIGH) {
      Serial.write('p');
    }



    //switch(inByte) {
    //case 'r': //Data request
    //  lcd.print("Msg rcvd:");
    //  lcd.setCursor(0,1); //Move cursor to second row
    //  lcd.print(inByte);
    //  Serial.write('s');
    //  break;
    //}
    Serial.flush();
  }
}






