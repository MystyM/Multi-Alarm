#include <SPI.h>
#include <nRF24L01.h>
#include "RF24.h"


#define led1 4

int buttonState = 1;
int time = 0;
int buzzer1 = 2;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  digitalWrite(led1, LOW);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_250KBPS );
  radio.startListening();
}

void loop() {
  if(radio.available()) {
    while (!radio.available());
    radio.read(&buttonState, sizeof(buttonState));
    
    Serial.println(buttonState);

    if (buttonState == 1) {
      digitalWrite(led1, LOW);
      time = 0;
    }
    else {
      digitalWrite(led1, HIGH);
      delay(1000);
      time = time+1;
    }
    if(time == 2) {
      tone(buzzer1, 392); // 
      delay(500);

      noTone(buzzer1); // pause
      delay(20);
      
      tone(buzzer1, 392); // 
      delay(500);

      noTone(buzzer1); // pause
      delay(20);
      
      tone(buzzer1, 392); // 
      delay(500);

      noTone(buzzer1); // pause
      delay(20);
      
      tone(buzzer1, 311.13); // 
      delay(2000);

      noTone(buzzer1); // pause
      delay(500);
      
      tone(buzzer1, 349.23); // E4
      delay(500);

      noTone(buzzer1); // pause
      delay(20);

      tone(buzzer1, 349.23); // E4
      delay(500);

      noTone(buzzer1); // pause
      delay(20);
      tone(buzzer1, 349.23); // E4
      delay(500);

      noTone(buzzer1); // pause
      delay(20);
      
      tone(buzzer1, 293.66); // F4
      delay(2000);

      noTone(buzzer1); // OFF
    }
  }
}
