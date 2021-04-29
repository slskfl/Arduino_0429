#include <SoftwareSerial.h>
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C4 523
SoftwareSerial BTSerial(2, 3);
int spPin=8;
int noteDuration=250;//음의 길이
int NOTES[8]={NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C4};
String buffer="";
void setup() {
  // put your setup code here, to run once:
  pinMode(spPin, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() { 
  // 블루투스 데이터 수신
  if(BTSerial.available()){
    byte data=BTSerial.read();
    if(data=='\n'){
      int indext=buffer.toInt();
      tone(spPin, NOTES[data], noteDuration);
    }else {
      buffer=(char)data;
    }
  }
}
