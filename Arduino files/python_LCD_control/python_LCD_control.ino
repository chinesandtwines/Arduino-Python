#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(7, OUTPUT); //Red LED
  lcd.print("init done");
  delay(1000);
  lcd.clear();
  //String test;
  
  int index;
  boolean started = false;
  boolean ended = false;
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    
    if (inByte == '<') {
      started = true;
      index = 0;
      inData[index] = '\0';
    }
    else if(inByte == '>') {
      ended = true;
    }
    else if(started) {
      inData[index] = inByte;
      index++;
      inData[index] = '\0';
    }
    
    if (started && ended) {
      lcd.print(inData);
    }
      // Convert he string to an integer
    //String string = String(inByte);
    //Serial.print(string);
    //lcd.print(string);
    //delay(1000);
    //lcd.clear();
    //switch(inByte) {
    //case 'try': 
    //  lcd.print("Msg rcvd:");
    //  lcd.setCursor(0,1); //Move cursor to second row
    //  lcd.print(inByte);
    //  Serial.write('s');
    //  break;
    //default:
      //digitalWrite(7, HIGH);
      //delay(500);
      //digitalWrite(7, LOW);
    //}
    Serial.flush();
  }
}


