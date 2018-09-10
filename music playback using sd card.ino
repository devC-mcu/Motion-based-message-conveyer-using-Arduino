#include "SD.h"         // sd card libraries
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
tmrpcm.speakerPin = 9;       // pin for aduio output connected to the speaker
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

tmrpcm.setVolume(5);          // sets the music volume
tmrpcm.play("test.wav");      // plays the music file named test.wav from sd card
}
// audio will be played once on every reset
void loop(){  }

