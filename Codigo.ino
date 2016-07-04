#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9

int pir =2;
int pirState;
int red1=3;
int red2=4;
int green=5;
int pushbutton=6;
int buttonState = 0;
int count=0;
int x=0;
int speaker=7;
int sensorMQ2 = A0;
int sensorMQ2Valores = 0;
int limiteMQ2 = 1300;

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(pir, INPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pushbutton, INPUT);
  pinMode(speaker, OUTPUT);
  pirState=LOW;
}

void loop() {
  sensorMQ2Valores = analogRead(sensorMQ2);
  pirState = digitalRead(pir);
  Serial.println("Valor actual MQ-2: ");
  Serial.println(sensorMQ2Valores, DEC);
  x=0;

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  Serial.print("Tap card key: ");
  Serial.println(strID);

  // Test Led
  if (strID.indexOf("E4:0A:BA:EB") >= 0) {
     while(x!=1){
        alarm(300,160);
           
           buttonState = digitalRead(pushbutton);
           if(buttonState==HIGH){
              count+=1;
            }     
            if(count==1){
		x=1;
              stopalarm();
              count=0;
              delay(1000);            
              }
        }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  if(pirState==HIGH){
      while(x!=1){
        alarm(300,160);
           
           buttonState = digitalRead(pushbutton);
           if(buttonState==HIGH){
              count+=1;
            }     
            if(count==1){
		x=1;
              stopalarm();
              count=0;
              delay(1000);            
              }
        }
  }
  else if(sensorMQ2Valores >= limiteMQ2) {
     while(x!=1){
        alarm(300,160);
           
           buttonState = digitalRead(pushbutton);
           if(buttonState==HIGH){
              count+=1;
            }     
            if(count==1){
		x=1;
              stopalarm();
              count=0;
              delay(1000);            
              }
        }
  }
  else{
    stopalarm();
  }      
}

void alarm(long duration,int frequency){
  digitalWrite(green, LOW);
  digitalWrite(red2,LOW);
  digitalWrite(red1, HIGH);
  delay(300);
  digitalWrite(red1, LOW);
  digitalWrite(red2, HIGH);
  delay(300);
  play(duration, frequency);
}

void play(long duration, int frequency){
  duration = duration*1000;
  int period = (1.0/frequency)*1000000;
  long elapsed = 0;
  while(elapsed<duration){
    digitalWrite(speaker, HIGH);
    delayMicroseconds(period/2);
    digitalWrite(speaker, LOW);
    delayMicroseconds(period/2);
    elapsed+= period;
  }
}

void stopalarm(){
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green, HIGH); 
  pirState=LOW;
  delay(700);
}
