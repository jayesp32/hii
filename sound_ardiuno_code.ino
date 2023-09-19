#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup() {
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  
  tmrpcm.setVolume(5);
}

void loop() {
  // Check if there is data available to read from the serial port
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // Read the incoming command
    
    // Process the command
    if (command == "command30") {
      // Play "1.wav" audio file
      tmrpcm.play("1.wav");
    } else if (command == "command31") {
      // Play "2.wav" audio file
      tmrpcm.play("2.wav");
    } else if (command == "command32") {
      // Play "3.wav" audio file
      tmrpcm.play("3.wav");
    } else if (command == "command33") {
      // Play "4.wav" audio file
      tmrpcm.play("4.wav");
    } else if (command == "command34") {
      // Play "5.wav" audio file
      tmrpcm.play("5.wav");
    } else if (command == "command35") {
      // Play "6.wav" audio file
      tmrpcm.play("6.wav");
    } else if (command == "command36") {
      // Play "7.wav" audio file
      tmrpcm.play("7.wav");
    } else if (command == "command37") {
      // Play "8.wav" audio file
      tmrpcm.play("8.wav");
    } else if (command == "command38") {
      // Play "9.wav" audio file
      tmrpcm.play("9.wav");
    } else if (command == "command39") {
      // Play "10.wav" audio file
      tmrpcm.play("10.wav");
    } else if (command == "command40") {
      // Play "11.wav" audio file
      tmrpcm.play("11.wav");
    } else if (command == "command41") {
      // Play "12.wav" audio file
      tmrpcm.play("12.wav");
    } else if (command == "command42") {
      // Play "13.wav" audio file
      tmrpcm.play("13.wav");
    } else if (command == "command43") {
      // Play "14.wav" audio file
      tmrpcm.play("14.wav");
    } else if (command == "command44") {
      // Play "15.wav" audio file
      tmrpcm.play("15.wav");
    } else if (command == "command45") {
      // Play "16.wav" audio file
      tmrpcm.play("16.wav");
    } else if (command == "command46") {
      // Play "17.wav" audio file
      tmrpcm.play("17.wav");
    } else if (command == "command47") {
      // Play "18.wav" audio file
      tmrpcm.play("18.wav");
    } else if (command == "command48") {
      // Play "19.wav" audio file
      tmrpcm.play("19.wav");
    } else if (command == "command49") {
      // Play "20.wav" audio file
      tmrpcm.play("20.wav");
    } else if (command == "command50") {
      // Play "21.wav" audio file
      tmrpcm.play("21.wav");
    } else if (command == "command51") {
      // Play "22.wav" audio file
      tmrpcm.play("22.wav");
    } else if (command == "command52") {
      // Play "23.wav" audio file
      tmrpcm.play("23.wav");
    } else if (command == "command53") {
      // Play "24.wav" audio file
      tmrpcm.play("24.wav");
    } else if (command == "command54") {
      // Play "25.wav" audio file
      tmrpcm.play("25.wav");
    } else if (command == "command55") {
      // Play "26.wav" audio file
      tmrpcm.play("26.wav");
    } else if (command == "command56") {
      // Play "27.wav" audio file
      tmrpcm.play("27.wav");
    } else if (command == "command57") {
      // Play "28.wav" audio file
      tmrpcm.play("28.wav");
    } else if (command == "command58") {
      // Play "29.wav" audio file
      tmrpcm.play("29.wav");
    } else if (command == "command59") {
      // Play "30.wav" audio file
      tmrpcm.play("30.wav");
    } else if (command == "command60") {
      // Play "31.wav" audio file
      tmrpcm.play("31.wav");
    } else if (command == "command61") {
      // Play "32.wav" audio file
      tmrpcm.play("32.wav");
    } else if (command == "command62") {
      // Play "33.wav" audio file
      tmrpcm.play("33.wav");
    } else if (command == "command63") {
      // Play "34.wav" audio file
      tmrpcm.play("34.wav");
    } else if (command == "command64") {
      // Play "35.wav" audio file
      tmrpcm.play("35.wav");
    } else if (command == "command65") {
      // Play "36.wav" audio file
      tmrpcm.play("36.wav");
    } else if (command == "command66") {
      // Play "37.wav" audio file
      tmrpcm.play("37.wav");
    } else if (command == "command67") {
      // Play "38.wav" audio file
      tmrpcm.play("38.wav");
    } else if (command == "command68") {
      // Play "39.wav" audio file
      tmrpcm.play("39.wav");
    } else if (command == "command69") {
      // Play "40.wav" audio file
      tmrpcm.play("40.wav");
    } else if (command == "command70") {
      // Play "41.wav" audio file
      tmrpcm.play("41.wav");
    } else if (command == "command71") {
      // Play "42.wav" audio file
      tmrpcm.play("42.wav");
    } else if (command == "command72") {
      // Play "43.wav" audio file
      tmrpcm.play("43.wav");
    } else if (command == "command73") {
      // Play "44.wav" audio file
      tmrpcm.play("44.wav");
    } else if (command == "command74") {
      // Play "45.wav" audio file
      tmrpcm.play("45.wav");
    } else if (command == "command75") {
      // Play "46.wav" audio file
      tmrpcm.play("46.wav");
    } else if (command == "command76") {
      // Play "47.wav" audio file
      tmrpcm.play("47.wav");
    } else if (command == "command77") {
      // Play "48.wav" audio file
      tmrpcm.play("48.wav");
    } else if (command == "command78") {
      // Play "49.wav" audio file
      tmrpcm.play("49.wav");
    } else if (command == "command79") {
      // Play "50.wav" audio file
      tmrpcm.play("50.wav");
    } else {
      // Invalid command
      Serial.println("Invalid command.");
    }
  }
}
