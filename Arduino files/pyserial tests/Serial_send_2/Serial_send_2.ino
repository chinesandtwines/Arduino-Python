// Open a serial connection and flash LED when input is received

int ledRed = 2;      // LED connected to digital pin 4
int ledGreen = 4;

void setup(){
  // Open serial connection.
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  delay(1000);  
}

void loop(){
  if(Serial.available() > 0){      // if data present, blink
        digitalWrite(ledRed, HIGH);
        delay(1000);             
        digitalWrite(ledRed, LOW);
        delay(1000);
        Serial.flush();
  }
  else{
     digitalWrite(ledGreen, HIGH);
        delay(1000);             
        digitalWrite(ledGreen, LOW);
        delay(1000);
  }
}
