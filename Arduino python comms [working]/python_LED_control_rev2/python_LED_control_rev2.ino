#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char inData[16];
int index;
boolean started = false;
boolean ended = false;
char firstchar;


void setup() {
  pinMode(7, OUTPUT); //Red LED
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("init done");
  delay(1000);
  lcd.clear();
}

void loop() {
  while(Serial.available() > 0) {
    char inByte = Serial.read();

    if(inByte == '<') { //indicates start of a msg
      started = true;
      index = 0;
      inData[index] = '\0'; //null character
    }

    else if(inByte == '>') { //indicates end of a msg
      ended = true;
    }

    else if (started) { //adds each incoming byte to a string
      inData[index] = inByte;
      index++;
      inData[index] = '\0';
    }
    //}

    if (started && ended) { //once entire msg is received
      // Use the value
      lcd.print("Msg rcvd:");
      lcd.setCursor(0,1); //Move cursor to second row
      for (int col = 1; col < 17; col++) {
        if (inData[col] != '\0' && inData[col-1] != '\0') {
          lcd.print(inData[col]);
          //delay(150); // for typing effect
        }
      }
            
      if (inData[0] == 'r') { //turn on red LED
          digitalWrite(7, HIGH);
          Serial.print("Red LED turned on \n");
          Serial.print(inData);
          break;
      }
          
        
      //Serial.write('s');

      //Get ready for the next time
      started = false;
      ended = false;

      index = 0;
      inData[index] = '\0';
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





