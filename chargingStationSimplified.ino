#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 32;

int dataPin  = 7;
int clockPin = 6;
//int piezoPin = A5;

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);//initialize strip

const uint32_t off = strip.Color(0,0,0);
const uint32_t white = strip.Color(10,10,10);
const uint32_t red = strip.Color(10,0,0);
const uint32_t yellow = strip.Color(10,10,0);
const uint32_t green = strip.Color(0,10,0);
const uint32_t cyan = strip.Color(0,10,10);
const uint32_t blue = strip.Color(0,0,10);
const uint32_t violet = strip.Color(10,0,10);

const int rainbowLength = 7;
uint32_t rainbow[rainbowLength] = {white,red,yellow,green,cyan,blue,violet};
float vibration;
int input;
int stripeLED = 0;
int stripeColor = 0;
int randLED = random(nLEDs);
int randR = random(128);
int randG = random(128);
int randB = random(128);
int blinkOn = false;
int currentTime = 0;
int timeOfLastRandomChange = 0;
int timeOfLastStripeChange = 0;
int timeOfLastBlinkChange = 0;
int randomDelay = 50;
int stripeDelay = 50;
int blinkDelay = 50;


void setup() {
  strip.begin();//start strip
  strip.show();//shows strip - initiatlly all off
  //pinMode(piezoPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  currentTime = millis();
  if((currentTime - timeOfLastRandomChange) >= randomDelay){
    randLED = random(nLEDs);
    randR = random(128);
    randG = random(128); 
    randB = random(128);
    timeOfLastRandomChange = currentTime;
  }
  strip.setPixelColor(randLED,strip.Color(randR,randG,randB));
  strip.show();
}
