#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"
#include <SoftwareSerial.h>

TMRpcm tmrpcm;
SoftwareSerial bluetooth(2, 3);  // Define a SoftwareSerial object to communicate with the Bluetooth module

void setup() {
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  bluetooth.begin(9600);  // Initialize Bluetooth communication

  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }

  tmrpcm.setVolume(5);
  tmrpcm.play("100.wav");  // Default file to play
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    int fileNumber;

    switch (command) {
      case '1':
        fileNumber = 1;
        break;
      case '2':
        fileNumber = 2;
        break;
      case '3':
        fileNumber = 3;
        break;
      case '4':
        fileNumber = 4;
        break;
      case '5':
        fileNumber = 5;
        break;
      case '6':
        fileNumber = 6;
        break;
      case '7':
        fileNumber = 7;
        break;
      case '8':
        fileNumber = 8;
        break;
      case '9':
      tmrpcm.play("9.wav");
        delay(4500);
        tmrpcm.play("99.wav"); // Play "99.wav"
       delay(12500); 
        break;
      case '0':
        fileNumber = 10;
        break;
      case 'A':
        fileNumber = 11;
        break;
      case 'B':
        fileNumber = 12;
        break;
      case 'C':
        fileNumber = 13;
        break;
      case 'D':
        fileNumber = 14;
        break;
      case 'E':
        fileNumber = 15;
        break;
      case 'F':
        fileNumber = 16;
        break;
      case 'G':
        fileNumber = 17;
        break;
      case 'H':
        fileNumber = 18;
        break;
      case 'I':
        fileNumber = 19;
        break;
      case 'J':
        fileNumber = 20;
        break;
      case 'K':
        fileNumber = 21;
        break;
      case 'L':
        fileNumber = 22;
        break;
      case 'M':
        fileNumber = 23;
        break;
      case 'N':
        fileNumber = 24;
        break;
      case 'O':
        fileNumber = 25;
        break;
      case 'P':
        fileNumber = 26;
        break;
      case 'Q':
        fileNumber = 27;
        break;
      case 'R':
        fileNumber = 28;
        break;
      case 'S':
        fileNumber = 29;
        break;
      case 'T':
        fileNumber = 30;
        break;
      case 'U':
        fileNumber = 31;
        break;
      case 'V':
        fileNumber = 32;
        break;
      case 'W':
        fileNumber = 33;
        break;
      case 'X':
        fileNumber = 34;
        break;
      case 'Y':
        fileNumber = 35;
        break;
      case 'Z':
        fileNumber = 36;
        break;
      case 'a':
        fileNumber = 37;
        break;
      case 'b':
        fileNumber = 38;
        break;
      case 'c':
        fileNumber = 39;
        break;
      case 'd':
        fileNumber = 40;
        break;
      case 'e':
        fileNumber = 41;
        break;
      case 'f':
        fileNumber = 42;
        break;
      case 'g':
        fileNumber = 43;
        break;
      case 'h':
        fileNumber = 44;
        break;
      case 'i':
        fileNumber = 45;
        break;
      case 'j':
        fileNumber = 46;
        break;
      case 'k':
        fileNumber = 47;
        break;
      case 'l':
        fileNumber = 48;
        break;
      case 'm':
        fileNumber = 49;
        break;
      case 'n':
        fileNumber = 50;
        break;
      case 'o':
        fileNumber = 51;
        break;
      case 'p':
        fileNumber = 52;
        break;
      case 'q':
        fileNumber = 53;
        break;
      case 'r':
        fileNumber = 54;
        break;
      case 's':
        fileNumber = 55;
        break;
      case 't':
        fileNumber = 56;
        break;
      case 'u':
        fileNumber = 57;
        break;
      case 'v':
        fileNumber = 58;
        break;
      case 'w':
        fileNumber = 59;
        break;
      case 'x':
        fileNumber = 60;
        break;
      case 'y':
        fileNumber = 61;
        break;
      case 'z':
        fileNumber = 62;
        break;
      default:
        // Handle unsupported commands or errors
        break;
    }

    if (fileNumber >= 1 && fileNumber <= 70) { // Adjust upper bound for the total number of commands
      char fileName[8];  // You may need to adjust the array size based on your file names
      sprintf(fileName, "%d.wav", fileNumber);
      tmrpcm.play(fileName);
    }
  }
}
