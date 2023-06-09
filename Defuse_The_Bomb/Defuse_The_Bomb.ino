#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>
#include <Wire.h>
#include <SPI.h>


const uint8_t spLONG[] PROGMEM = {0x6C,0xB1,0xAE,0x5D,0x4D,0x93,0x9A,0xCB,0xB9,0x14,0x4F,0xB7,0x2D,0x4E,0x5B,0x4C,0x22,0x9D,0xAD,0xDB,0x5C,0xA3,0x28,0x57,0x77,0x6D,0xF5,0xC9,0xD3,0x42,0xD2,0xAE,0x29,0x98,0xA9,0x08,0xCA,0x72,0x86,0x68,0xB7,0x23,0xA8,0xCB,0xE9,0xA2,0xBD,0x36,0x97,0x2C,0xAB,0x0E,0xE1,0x52,0x43,0x5B,0xAF,0x22,0xD4,0x31,0x8B,0x58,0xB4,0xB2,0x58,0xDB,0xDC,0xB2,0xF1,0x48,0xB3,0x6C,0x5F,0x0A,0x25,0x2D,0x2D,0x5A,0xAB,0xD9,0x54,0x8F,0xAC,0x28,0xCE,0x92,0x54,0x34,0xF2,0xEA,0xC4,0x9B,0xCB,0xF2,0xFF,0x03};
const uint8_t spSHORT[] PROGMEM = {0x0C,0x38,0x71,0x54,0x01,0xBB,0x6D,0x19,0x60,0x97,0xEB,0x00,0xEC,0xB2,0x16,0x80,0x95,0x2F,0x02,0x30,0xFB,0xB8,0x03,0x7A,0x0E,0x69,0x45,0xF5,0x1D,0x21,0x22,0xA7,0x95,0xD1,0xB6,0x6B,0xB1,0xF6,0x56,0x87,0xD6,0x62,0xC9,0xDE,0x5A,0x1B,0x46,0x72,0x2C,0x7A,0x6B,0x5D,0x1C,0x81,0x35,0x98,0xA7,0x4C,0xA9,0x3A,0xE6,0xAA,0x1F,0x04,0x4E,0x51,0xAA,0x42,0x35,0x00,0x40,0x01,0x43,0xBA,0x31,0x60,0x73,0x35,0x04,0x4E,0x51,0xAA,0x42,0x35,0xFE,0x1F};
const uint8_t spTIME[] PROGMEM = {0x0E,0x18,0xA2,0x34,0x00,0x4B,0x0E,0x2B,0x20,0x5B,0xB7,0x51,0xA4,0x94,0x5A,0xAE,0xA5,0x56,0x99,0x4B,0x6B,0xBA,0xCC,0x5D,0x75,0x8E,0x63,0xD6,0x32,0x67,0x35,0x39,0x8F,0x5A,0xEB,0x9C,0x35,0x16,0xBF,0x26,0x2D,0x4B,0xD6,0x58,0xED,0x39,0x8D,0xAE,0x59,0x47,0xD3,0x1B,0xDC,0xD2,0x66,0x9C,0x5D,0xB6,0xC9,0xE8,0xEA,0x76,0x37,0x9F,0x62,0x6D,0x8B,0xCB,0xD3,0x42,0x88,0x8C,0x2D,0x2A,0x6F,0x8B,0x6A,0x1E,0x36,0xA5,0x7C,0xD5,0xB1,0xBB,0x78,0xE2,0xF2,0x56,0x4B,0x6E,0xEA,0x4E,0xCA,0x5B,0x3D,0x87,0xA8,0x39,0x09,0x6F,0x75,0xE2,0xA6,0x6A,0xF7,0xFF,0x01};
const uint8_t spLEVEL[] PROGMEM = {0x69,0xAB,0xC4,0xB3,0xD8,0x92,0x86,0x2D,0x83,0xEE,0x60,0xCD,0x12,0xD6,0x0C,0x66,0x45,0x2C,0x73,0x58,0x0B,0xA8,0x53,0xD6,0xAC,0x6D,0xE9,0xC0,0x57,0xC5,0xB2,0xAE,0xA1,0xB0,0x49,0x0D,0x7B,0xBD,0x86,0xA2,0x47,0x35,0xE3,0xF5,0xEA,0xB2,0x4B,0x4B,0xCB,0xC7,0xA3,0xCD,0xDE,0x23,0x59,0x1A,0x9A,0x31,0x8B,0xB0,0x54,0x76,0xE3,0xC6,0x26,0x5C,0x2C,0xCC,0x76,0x6B,0x92,0xBC,0x34,0x95,0xC6,0xA3,0xCE,0x74,0xDB,0x85,0x3B,0x8F,0xBA,0x90,0x9C,0x51,0xCC,0xD6,0xEA,0x4C,0x63,0x56,0x30,0x6D,0xA9,0x23,0xCF,0x59,0xD0,0x34,0xB5,0xF9,0x7F};
const uint8_t spTHREE[] PROGMEM = {0x0C,0xE8,0x2E,0x94,0x01,0x4D,0xBA,0x4A,0x40,0x03,0x16,0x68,0x69,0x36,0x1C,0xE9,0xBA,0xB8,0xE5,0x39,0x70,0x72,0x84,0xDB,0x51,0xA4,0xA8,0x4E,0xA3,0xC9,0x77,0xB1,0xCA,0xD6,0x52,0xA8,0x71,0xED,0x2A,0x7B,0x4B,0xA6,0xE0,0x37,0xB7,0x5A,0xDD,0x48,0x8E,0x94,0xF1,0x64,0xCE,0x6D,0x19,0x55,0x91,0xBC,0x6E,0xD7,0xAD,0x1E,0xF5,0xAA,0x77,0x7A,0xC6,0x70,0x22,0xCD,0xC7,0xF9,0x89,0xCF,0xFF,0x03};
const uint8_t spTWO[]  PROGMEM = {0x06,0xB8,0x59,0x34,0x00,0x27,0xD6,0x38,0x60,0x58,0xD3,0x91,0x55,0x2D,0xAA,0x65,0x9D,0x4F,0xD1,0xB8,0x39,0x17,0x67,0xBF,0xC5,0xAE,0x5A,0x1D,0xB5,0x7A,0x06,0xF6,0xA9,0x7D,0x9D,0xD2,0x6C,0x55,0xA5,0x26,0x75,0xC9,0x9B,0xDF,0xFC,0x6E,0x0E,0x63,0x3A,0x34,0x70,0xAF,0x3E,0xFF,0x1F};
const uint8_t spONE[] PROGMEM = {0x66,0x4E,0xA8,0x7A,0x8D,0xED,0xC4,0xB5,0xCD,0x89,0xD4,0xBC,0xA2,0xDB,0xD1,0x27,0xBE,0x33,0x4C,0xD9,0x4F,0x9B,0x4D,0x57,0x8A,0x76,0xBE,0xF5,0xA9,0xAA,0x2E,0x4F,0xD5,0xCD,0xB7,0xD9,0x43,0x5B,0x87,0x13,0x4C,0x0D,0xA7,0x75,0xAB,0x7B,0x3E,0xE3,0x19,0x6F,0x7F,0xA7,0xA7,0xF9,0xD0,0x30,0x5B,0x1D,0x9E,0x9A,0x34,0x44,0xBC,0xB6,0x7D,0xFE,0x1F};
const uint8_t spGREAT[] PROGMEM = {0x6E,0xF3,0x59,0xC2,0x46,0xD9,0xA9,0xCD,0x0C,0x95,0x0E,0x55,0x6E,0x36,0x3D,0x9D,0xAA,0x4C,0xAE,0xD9,0xF4,0x0C,0xCC,0x36,0x7B,0x6E,0xF5,0x8B,0xF4,0x4C,0xB2,0x95,0x29,0x76,0xCC,0xD2,0xF4,0xB6,0xA6,0x5C,0xC4,0xD3,0xAA,0xEF,0x9A,0xAA,0x2F,0x8C,0x8C,0x4D,0x6B,0x19,0x6E,0x48,0xD2,0x56,0xAD,0x7D,0xB8,0x42,0x4E,0x5F,0xDD,0xCE,0x6E,0x0C,0x7C,0x72,0x71,0x38,0x87,0x36,0xD0,0xCE,0xD9,0x6C,0x1B,0x5A,0xC9,0x22,0x12,0x23,0x70,0x8A,0x52,0x15,0xAA,0x01,0x00,0x0E,0x18,0xD2,0xCD,0x01,0x9B,0xAB,0x09,0xE0,0x98,0x2D,0x01,0x2C,0x15,0x86,0x80,0x1A,0x15,0xFE,0x1F};
const uint8_t spSTART[] PROGMEM = {0x02,0xF8,0x49,0xCC,0x00,0xBF,0x87,0x3B,0xE0,0xB7,0x60,0x03,0xFC,0x9A,0xAA,0x80,0x3F,0x92,0x11,0x30,0x29,0x9A,0x02,0x86,0x34,0x5F,0x65,0x13,0x69,0xE2,0xDA,0x65,0x35,0x59,0x8F,0x49,0x59,0x97,0xD5,0x65,0x7D,0x29,0xA5,0xDE,0x56,0x97,0xF5,0x85,0x8E,0xE4,0x5D,0x6D,0x0E,0x23,0x39,0xDC,0x79,0xD4,0xA5,0x35,0x75,0x72,0xEF,0x51,0x95,0xE9,0x38,0xE6,0xB9,0x4B,0x5D,0x1A,0x26,0x6B,0x3B,0x46,0xE0,0x14,0xA5,0x2A,0x54,0x03,0x40,0x01,0x43,0xBA,0x31,0x60,0x73,0x35,0x04,0x4E,0x51,0xAA,0x42,0x35,0xFE,0x1F};
const uint8_t spAGAIN[]             PROGMEM ={0x08,0xD0,0xD1,0xBD,0x55,0xAE,0xA7,0x73,0x54,0xAD,0x53,0xC5,0x18,0xE1,0xA2,0x4B,0x4F,0x9D,0x42,0xA8,0x89,0x76,0x6D,0xB5,0xB7,0x22,0x21,0xE9,0xAD,0x36,0xB3,0x1D,0x4D,0xB1,0x22,0xAE,0x97,0xA4,0xE7,0x23,0x2B,0x89,0x5D,0x63,0x92,0xEC,0x6C,0xA7,0x23,0x2D,0xD5,0x42,0x74,0x14,0xCF,0x6C,0xE4,0xA9,0x45,0x08,0x8D,0xE3,0x5D,0xEF,0x66,0xB4,0xB1,0x67,0xB2,0x66,0xE2,0xD9,0x8F,0x3E,0x8C,0x08,0xF2,0x8C,0x1B,0x06,0xE9,0xA5,0xCC,0x46,0xB6,0x1F,0xEC,0x20,0x07,0x34,0xD0,0x10,0x99,0xDA,0x92,0x1E,0x00,0x00};
const uint8_t spIN[] PROGMEM = {0x65,0xED,0xD6,0xD1,0x2A,0x3F,0xB5,0x65,0x98,0x40,0xED,0xDA,0x3C,0xE6,0xA1,0x13,0x79,0x72,0xF5,0x1A,0x87,0x09,0x94,0x8E,0xC7,0x63,0x6C,0xDE,0xD1,0x2A,0x2F,0xB7,0xB1,0x7A,0xE7,0x88,0xBC,0x9C,0xA6,0xE6,0x30,0x53,0xCD,0x49,0x99,0x9A,0xA5,0x70,0x73,0xC7,0x65,0x6A,0x86,0x22,0xD5,0x9D,0xA4,0xB9,0x19,0x8C,0xD0,0x70,0x1D,0xE6,0xAA,0x31,0x4B,0xDD,0x8D,0x5B,0xB2,0xC4,0x31,0xCD,0x44,0xFF,0x0F};
const uint8_t spTEN[] PROGMEM = {0x0A,0xD8,0x5C,0x4D,0x03,0x2B,0xAB,0x5E,0xC4,0x33,0x2B,0xAF,0x62,0x84,0x12,0x0D,0x7B,0xB3,0xCA,0x66,0x43,0xA2,0xE3,0xF6,0xAA,0xAA,0x4E,0xC9,0x89,0xDB,0xAB,0x6E,0xBA,0xC5,0xDB,0x66,0xAF,0xB9,0xE8,0xE6,0x4C,0xBF,0x3D,0xE6,0x6A,0xC4,0x4B,0xCA,0x49,0xD9,0xBA,0x61,0x2B,0x09,0x25,0xED,0xE8,0x5A,0xB4,0xC4,0xED,0xA6,0x6B,0x18,0xE1,0x56,0xB7,0x9A,0xAE,0xA6,0x44,0x47,0xDC,0x6E,0xBE,0xC2,0xDD,0xA5,0xF0,0xB8,0xD9,0xFD,0x7F};
const uint8_t spSECONDS[]       PROGMEM = {0x04,0xF8,0xC5,0x51,0x01,0xBF,0xA6,0x6A,0x40,0x03,0x16,0xD0,0xC0,0xCA,0xAB,0x75,0x2D,0xCD,0x25,0x37,0xBB,0xD9,0xCA,0xDA,0x54,0x0F,0xEE,0xD9,0x29,0x6B,0x47,0x30,0xD8,0xE3,0x80,0x00,0x6A,0x26,0x6D,0x55,0xEB,0xCA,0x21,0xB9,0xE4,0xD4,0xDD,0x26,0xA5,0xF9,0xE3,0x3D,0xB6,0x75,0x38,0xA3,0x31,0x5B,0x9A,0xB6,0x11,0x51,0x32,0xD2,0xAA,0x3F,0xFC,0x21,0xCE,0x22,0xD1,0xD7,0x2D,0x9E,0x39,0x0B,0x37,0x4E,0xD7,0x26,0xE1,0xFA,0xC4,0x55,0x42,0xFD,0x85,0xFB,0x7B,0x77,0x13,0xA3,0x27,0x80,0x03,0xD0,0x25,0x20,0x01,0x0A,0x20,0x20,0x69,0xD6,0xFF,0x07};
const uint8_t spFAILURE[] PROGMEM = {0x04,0x18,0xB6,0x82,0x02,0x04,0x98,0xBE,0x42,0x00,0xD3,0xA5,0x6B,0x60,0xD5,0xC3,0x95,0x48,0xC8,0x96,0xD5,0x0D,0x57,0xCC,0xA5,0xAB,0x57,0xDF,0x54,0xB0,0xB5,0xAD,0x5E,0xC3,0x60,0x95,0x62,0x9A,0xAE,0x2D,0x9D,0xBA,0x7B,0xA8,0xF7,0xB4,0x36,0x19,0x4E,0xEE,0xE9,0xCA,0xDA,0x75,0x20,0xB7,0x6D,0x69,0x6B,0xD3,0x81,0x32,0xB1,0xA6,0x6D,0xCD,0x05,0x68,0x47,0xDF,0xB2,0x37,0x5F,0x24,0x2D,0x5D,0xC2,0x55,0x5C,0x92,0x9C,0xF4,0x09,0x6F,0xB6,0x85,0x76,0x96,0xC5,0xBD,0xD9,0x37,0xE8,0x9A,0x3E,0xF7,0xE6,0x16,0x90,0x69,0xDE,0xDC,0x97,0xAB,0x63,0xB4,0xA7,0xFD,0x7F};

int ranPix0Col = 0;
int ranPix1Col = 0;
int ranPix2Col = 0;
int ranPix3Col = 0;
int ranPix4Col = 0;
int ranPix5Col = 0;
int ranPix6Col = 0;
int ranPix7Col = 0;
int ranPix8Col = 0;
int ranPix9Col = 0;


int buttonA = 4;
int buttonB = 5;
int slideSwitch = 7;
int switchState = 0;
volatile bool aFlag = 0;
volatile bool switchFlag = 0;
volatile bool bFlag = 0;
float totalAccel = 0;
int lightVal = 0;
int capA1Val = 500;
int capA6Val = 500;
int capA5Val = 500;
int switchVal = 0;
float X = 0;
float Y = 0;
float Z = 0;
int soundTrials = 0;
int averageSound = 0;
int handicapTime = 0;
AsyncDelay gameTimer;

void calculateAccel(){
  X = 0;
  Y = 0;
  Z = 0;
  for (int a=0; a<10; a++) {
    X += CircuitPlayground.motionX();             // This function "calculateAccel" is from an example given in class
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }
  X /= 10;
  Y /= 10;
  Z /= 10;
  totalAccel = sqrt(X*X + Y*Y + Z*Z);
  Serial.println(totalAccel);
  delay(1);
}

void deathSparkle(){
  for(int i = 0; i < 250; i++){
    int randomPixel = random(0, 10);
    CircuitPlayground.setPixelColor(randomPixel, 255, 0, 0);
    delay(10);
    CircuitPlayground.clearPixels();
  }
}

void youWin(){
  for(int o = 0; o < 3; o++){
    for(int j = 0; j < 255; j++){
      for(int i = 0; i < 10; i++){
        CircuitPlayground.setPixelColor(i, 0, j, 0);
      }
    }
  }
}

void calculateLight(){
  lightVal = CircuitPlayground.lightSensor();
}

void speakNormalMode(){
  CircuitPlayground.speaker.say(spLONG);
  CircuitPlayground.speaker.say(spTIME);
  CircuitPlayground.speaker.say(spLEVEL);
}

void speakHardMode(){
  CircuitPlayground.speaker.say(spSHORT);
  CircuitPlayground.speaker.say(spTIME);
  CircuitPlayground.speaker.say(spLEVEL);
}

void speakStartGame(){
  CircuitPlayground.speaker.say(spSTART);
  CircuitPlayground.speaker.say(spIN);
  CircuitPlayground.speaker.say(spTHREE);
  delay(1000);
  CircuitPlayground.speaker.say(spTWO);
  delay(1000);
  CircuitPlayground.speaker.say(spONE);
  delay(1000);
  CircuitPlayground.playTone(440, 400);
}

void speakVictory(){
  CircuitPlayground.playTone(261.63, 50);
  delay(1);
  CircuitPlayground.playTone(392, 50);
  delay(1);
  CircuitPlayground.playTone(523.25, 50);
  delay(1);
  CircuitPlayground.playTone(293.66, 50);
  delay(1);
  CircuitPlayground.playTone(369.99, 50);
  delay(1);
  CircuitPlayground.playTone(587.33, 50);
  delay(1);
  CircuitPlayground.playTone(659.25, 200);
  delay(1);
  youWin();
  CircuitPlayground.speaker.say(spGREAT);
  delay(500);
  CircuitPlayground.speaker.say(spSTART);
  CircuitPlayground.speaker.say(spAGAIN);
  CircuitPlayground.speaker.say(spIN);
  CircuitPlayground.speaker.say(spTEN);
  CircuitPlayground.speaker.say(spSECONDS);
}

void speakFailure(){
  CircuitPlayground.playTone(311.13, 300);
  delay(1);
  CircuitPlayground.playTone(293.66, 300);
  delay(1);
  CircuitPlayground.playTone(277.18, 300);
  delay(1);
  CircuitPlayground.playTone(261.63, 300);
  delay(1);
  deathSparkle();
  CircuitPlayground.speaker.say(spFAILURE);
  delay(500);
  CircuitPlayground.speaker.say(spSTART);
  CircuitPlayground.speaker.say(spAGAIN);
  CircuitPlayground.speaker.say(spIN);
  CircuitPlayground.speaker.say(spTEN);
  CircuitPlayground.speaker.say(spSECONDS);
}
void pixelDefused(int pixelNum){
  for(int i = 255; i > 0; i--){
    CircuitPlayground.setPixelColor(pixelNum, i, i, i);
    delay(1);
  }
}

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  attachInterrupt(digitalPinToInterrupt(buttonA), buttonAPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonB), buttonBPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(slideSwitch), switchMoved, CHANGE);
  randomSeed(analogRead(0));
}

void loop() {
  randoPixels();
  switchState = CircuitPlayground.slideSwitch();
    if(!switchState){
      speakHardMode();
      handicapTime = 30000;
    }
    else{
      speakNormalMode();
      handicapTime = 0;
    }
  speakStartGame();
  CircuitPlayground.speaker.set(255);
  gameTimer.start(60000-handicapTime, AsyncDelay::MILLIS);
  for(int pixelsDefused = 0; pixelsDefused < 10; pixelsDefused++){
    switch(pixelsDefused){
    case 0:
      if(ranPix0Col == 0){
        while(!(aFlag && bFlag)){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(0);
        initializeEverything();
        break;
      }
      else if(ranPix0Col == 1){
        while(capA1Val < 1000){
          if(gameTimer.isExpired()){
            break;
          }
          capA1Val = CircuitPlayground.readCap(6);
        }
        pixelDefused(0);
        initializeEverything();
        break;
      }
      else if(ranPix1Col == 0){
        while(capA1Val < 800 || capA5Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA1Val = CircuitPlayground.readCap(6);
          capA5Val = CircuitPlayground.readCap(2);
        }
        pixelDefused(0);
        initializeEverything();
        break;
      }
      else if(ranPix1Col == 1){
        needsShaken(0);
        break;
      }
      else{
        needsLight(0);
        break;
      }
    case 1:
      if(ranPix1Col == 0){
        while(capA6Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA6Val = CircuitPlayground.readCap(1);
        }
        pixelDefused(1);
        initializeEverything();
        break;
      }
      else if(ranPix1Col == 1){
        for(int q = 0; q < 3; q++){
          while(!bFlag){
            if(gameTimer.isExpired()){
              break;
            }
            initializeEverything();
          }
        }
        pixelDefused(1);
        break;
      }
      else{
        needsLight(1);
        break;        
      }
    case 2:
      if(ranPix2Col == 1){
        while(!switchFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(2);
        initializeEverything();
        break;
      }
      else if(ranPix2Col == 2){
        needsLight(2);
        break;       
      }
      else if(ranPix5Col == 0){
          for(int q = 0; q < 2; q++){
            while(!aFlag){
              if(gameTimer.isExpired()){
                break;
              }
              initializeEverything();
            }
          }
          pixelDefused(2);
          break;      
      }
      else if(ranPix5Col == 1){
        while(capA5Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA5Val = CircuitPlayground.readCap(2);
        }
        pixelDefused(2);
        initializeEverything();
      }
      else{
        for(int q = 0; q < 2; q++){
          while(!bFlag){
            if(gameTimer.isExpired()){
              break;
            }
            initializeEverything();
          }
        }
        pixelDefused(2);
        break;        
      }
    case 3:
      if(ranPix3Col == 0){
        needsShaken(3);
        break;        
      }
      else if(ranPix3Col == 1){
        needsLight(3);
        break;           
      }
      else{
        while(!switchFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(3);
        initializeEverything();
        break;        
      }
    case 4:
      if(ranPix4Col == 0){
        while(!(aFlag && bFlag)){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(4);
        initializeEverything();
        break;        
      }
      else if(ranPix4Col == 1){
        needsLight(4);
        break;
      }
      else if(ranPix8Col == 0){
        needsShaken(4);
        break;         
      }
      else if(ranPix8Col == 1){
        while(!bFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(4);
        initializeEverything();
        break;
      }
      else{
        needsShaken(4);
        break;          
      }
    case 5:
      if(ranPix5Col == 0){
        while(!aFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        initializeEverything();
        while(!bFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        initializeEverything();
        while(!aFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        initializeEverything();
        pixelDefused(5);
        break;
      }
      else if(ranPix5Col == 1){
        needsShaken(5);
        break;            
      }
      else{
        while(capA1Val < 1000){
          if(gameTimer.isExpired()){
            break;
          }
          capA1Val = CircuitPlayground.readCap(6);
        }
        pixelDefused(5);
        initializeEverything();
        break;        
      }
    case 6:
      if(ranPix6Col == 0){
        while(!switchFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(6);
        initializeEverything();
        break;         
      }
      else if(ranPix6Col == 2){
        while(capA6Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA6Val = CircuitPlayground.readCap(1);
        }
        pixelDefused(6);
        initializeEverything();
        break;
      }
      else if(ranPix9Col == 0){
        for(int q = 0; q < 3; q++){
          while(!aFlag){
            if(gameTimer.isExpired()){
              break;
            }
            initializeEverything();
          }
        }
        pixelDefused(6);
        break;        
      }
      else if(ranPix9Col == 1){
        while(capA6Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA6Val = CircuitPlayground.readCap(1);
        }
        pixelDefused(6);
        initializeEverything();
        break;        
      }
      else{
        needsLight(6);
        break;        
      }
    case 7:
      if(ranPix7Col == 0){
        needsShaken(7);
        break;          
      }
      else if(ranPix7Col == 1){
        while(!bFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        initializeEverything();
        while(!aFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        initializeEverything();
        while(!(aFlag && bFlag)){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(7);
        initializeEverything();
        break;                        
      }
      else{
        while(capA6Val > 10){
          if(gameTimer.isExpired()){
            break;
          }
          capA6Val = CircuitPlayground.readCap(1);
        }
        pixelDefused(7);
        initializeEverything();        
      }
    case 8:
      if(ranPix8Col == 0){
        while(!switchFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(8);
        initializeEverything();
        break;           
      }
      else if(ranPix8Col == 2){
        while(capA1Val < 1000){
          if(gameTimer.isExpired()){
            break;
          }
          capA1Val = CircuitPlayground.readCap(6);
        }
        pixelDefused(8);
        initializeEverything();        
      }
      else if(ranPix9Col == 0){
        needsShaken(8);
        break;          
      }
      else if(ranPix9Col == 1){
        needsLight(8);
        break;        
      }
      else{
        while(!aFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(8);
        initializeEverything();
        break;        
      }
    case 9:
      if(ranPix9Col == 0){
        while(!(aFlag && bFlag)){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(9);
        initializeEverything();
        break;        
      }
      else if(ranPix9Col == 1){
        while(!switchFlag){
          if(gameTimer.isExpired()){
            break;
          }
        }
        pixelDefused(9);
        initializeEverything();
        break;         
      }
      else{
        needsShaken(9);
        break;         
      }
    } // switch case end
  } //for loop end
  CircuitPlayground.clearPixels();
  if(gameTimer.isExpired()){
    speakFailure();
  }
  else{
    speakVictory();
  }
  delay(10000);
} // loop end











void buttonAPressed(){
  aFlag = 1;
}
void buttonBPressed(){
  bFlag = 1;
}
void switchMoved(){
  switchFlag = 1;
}

void randoPixels(){
  ranPix0Col = random(0, 3);
  switch(ranPix0Col){
    case 0:
      CircuitPlayground.setPixelColor(0, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(0, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(0, 0, 0, 255);
  }
  delay(100);
  ranPix1Col = random(0, 3);
  switch(ranPix1Col){
    case 0:
      CircuitPlayground.setPixelColor(1, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(1, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(1, 0, 0, 255);
  }
  delay(100);
  ranPix2Col = random(0, 3);
  switch(ranPix2Col){
    case 0:
      CircuitPlayground.setPixelColor(2, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(2, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(2, 0, 0, 255);
  }
    delay(100);
  ranPix3Col = random(0, 3);
  switch(ranPix3Col){
    case 0:
      CircuitPlayground.setPixelColor(3, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(3, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(3, 0, 0, 255);
  }
    delay(100);
  ranPix4Col = random(0, 3);
  switch(ranPix4Col){
    case 0:
      CircuitPlayground.setPixelColor(4, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(4, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(4, 0, 0, 255);
  }
    delay(100);
  ranPix5Col = random(0, 3);
  switch(ranPix5Col){
    case 0:
      CircuitPlayground.setPixelColor(5, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(5, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(5, 0, 0, 255);
  }
    delay(100);
  ranPix6Col = random(0, 3);
  switch(ranPix6Col){
    case 0:
      CircuitPlayground.setPixelColor(6, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(6, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(6, 0, 0, 255);
  }
    delay(100);
  ranPix7Col = random(0, 3);
  switch(ranPix7Col){
    case 0:
      CircuitPlayground.setPixelColor(7, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(7, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(7, 0, 0, 255);
  }
    delay(100);
  ranPix8Col = random(0, 3);
  switch(ranPix8Col){
    case 0:
      CircuitPlayground.setPixelColor(8, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(8, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(8, 0, 0, 255);
  }
    delay(100);
  ranPix9Col = random(0, 3);
  switch(ranPix9Col){
    case 0:
      CircuitPlayground.setPixelColor(9, 255, 0, 0);
      break;
    case 1:
      CircuitPlayground.setPixelColor(9, 0, 255, 0);
      break;
    case 2:
      CircuitPlayground.setPixelColor(9, 0, 0, 255);
  }
}

void initializeEverything(){
  totalAccel = 0;
  switchFlag = 0;
  aFlag = 0;
  bFlag = 0;
  lightVal = 0;
  capA1Val = 500;
  capA5Val = 500;
  capA6Val = 500;
}

void needsShaken(int shakePixel){
  while(totalAccel < 30){
    calculateAccel();
    if(gameTimer.isExpired()){
      break;
    }
  }
  pixelDefused(shakePixel);
  initializeEverything();  
}

void needsLight(int lightPixel){
  while(lightVal < 500){
    calculateLight();
    if(gameTimer.isExpired()){
    break;
    }
  }
  pixelDefused(lightPixel);
  initializeEverything(); 
}
