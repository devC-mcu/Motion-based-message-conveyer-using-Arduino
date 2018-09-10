// Reciever code 
// rf ask module is used to receive the message


#include <RH_ASK.h>
#include <SPI.h>                     // Not actualy used but needed to compile
#include <VirtualWire.h>              
#include <LiquidCrystal.h>           // lcd library
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4          //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>                 //  library for ashynchronus playback of PCM/WAV files direct from sd card

TMRpcm tmrpcm;   // create an object for use in this sketch

const int rs = 8, en = 10, d4 = 6, d5 = 5, d6 = 7, d7 = 3;   // for lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean x = false;

RH_ASK driver;
// RH_ASK driver(2000, 2, 4, 5); // ESP8266 or ESP32: do not use pin 11


void music1(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  I AM HUNGRY   ");
    lcd.setCursor(1, 0);
    lcd.print("________________");
    tmrpcm.play("11.wav");
    x = true; 
    delay(1000);
}         // displays the text(I AM HUNGRY) on the lcd and plays the audio for this text
void music2(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  I AM THIRSTY  ");
    lcd.setCursor(1, 0);
    lcd.print("________________");
    tmrpcm.play("22.wav");
    x = true; delay(1000);
}         // displays the text(I AM THIRSTY) on the lcd and plays the audio for this text
void music3(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   NEED HELP    ");
    lcd.setCursor(1, 0);
    lcd.print("________________");
    tmrpcm.play("33.wav");
    x = true; delay(1000);
}           // displays the text(NEED HELP) on the lcd and plays the audio for this text
void music4(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOT FEELING WELL");
    lcd.setCursor(1, 0);
    lcd.print("________________");
    tmrpcm.play("44.wav");
    x = true; delay(1000);
}          // displays the text(NOT FEELING WELL) on the lcd and plays the audio for this text


void setup()
{
    Serial.begin(9600);     // Debugging only
    tmrpcm.speakerPin = 9;  // pin for audio output connected to the speaker
    lcd.begin(16, 2);        
      
    if (!driver.init()){
         Serial.println("init failed");
         }


    // for SD Card
    if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not

  }
  else{   
    Serial.println("SD ok");   
  }
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
  int i;

  // Message with a good checksum received, dump it.
    for (i = 0; i < buflen; i++){
      if(buf[i] == '1') {
          
          if(x == false){ music1();}
          }     // 1 is received by the receiver           
           
       if(buf[i] == '2'){
         
         if(x == false){ music2();}
         }      // 2 is received by the receiver
         
       if(buf[i] == '3'){
         
         if(x == false){ music3();}
        }      // 3 is received by the receiver   
        
       if(buf[i] == '4') {
    
         if(x == false){ music4();}
      }        // 4 is received by the receiver  
      
       if(buf[i] == '5'){
         x = false;
        }     // 5 is received by the receiver 
    }
}
}




