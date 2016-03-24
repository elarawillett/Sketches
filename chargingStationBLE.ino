#include "LPD8806.h"
#include "SPI.h"
#include "Adafruit_BLE_UART.h"

#define ADAFRUITBLE_REQ 10
#define ADAFRUITBLE_RDY 2
#define ADAFRUITBLE_RST 9

int nLEDs = 32;
int dataPin  = 7;
int clockPin = 6;

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);//initialize strip
Adafruit_BLE_UART uart = Adafruit_BLE_UART(ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST);//initialize BLE


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
int input = 0;
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
int asciiZero = 48;

void rxCallback(uint8_t *buffer, uint8_t len){
   input = (int)buffer[0]-asciiZero;
   //Serial.println(input);
}

void aciCallback(aci_evt_opcode_t event)
{
  switch(event)
  {
    case ACI_EVT_DEVICE_STARTED:
      Serial.println(F("Advertising started"));
      break;
    case ACI_EVT_CONNECTED:
      Serial.println(F("Connected!"));
      break;
    case ACI_EVT_DISCONNECTED:
      Serial.println(F("Disconnected or advertising timed out"));
      break;
    default:
      break;
  }
}

void setup() {
  strip.begin();//start strip
  strip.show();//shows strip - initiatlly all off
  Serial.begin(9600);
  uart.setRXcallback(rxCallback);//set callback function to the above
  uart.setACIcallback(aciCallback);
  uart.setDeviceName("LIGHTS"); /* 7 characters max! */
  uart.begin();//begin connection
  //pinMode(A0,INPUT);
}

void loop(){
  
  //Serial.println(analogRead(A0));
  uart.pollACI();//continually look for incoming data
  
  switch(input){
      
     case 0://all off
       for(int i=0; i<nLEDs; i++){
         strip.setPixelColor(i,off);
       }
       break;
     
     case 1://random
       currentTime = millis();
       if((currentTime - timeOfLastRandomChange) >= randomDelay){
         randLED = random(nLEDs);
         randR = random(128);
         randG = random(128); 
         randB = random(128);
         timeOfLastRandomChange = currentTime;
       }
       strip.setPixelColor(randLED,strip.Color(randR,randG,randB));
       break;
      
     case 2://rainbow stripes           
       currentTime = millis();
       if((currentTime - timeOfLastStripeChange) >= stripeDelay){
         stripeLED++;
         if(stripeLED==nLEDs){
           stripeColor++;
           stripeLED=0; 
         }      
         if(stripeColor==rainbowLength)
            stripeColor=0;
         timeOfLastStripeChange = currentTime;
       }
       strip.setPixelColor(stripeLED,rainbow[stripeColor]); 
       break;
      
     case 3://blinking
       currentTime = millis();
       if((currentTime - timeOfLastBlinkChange) >= blinkDelay){
         if(!blinkOn){
           for(int i=0; i<nLEDs; i++){    
             strip.setPixelColor(i,white);
           }
           blinkOn = true;
         }
         else{
           for(int i=0; i<nLEDs; i++){
             strip.setPixelColor(i,off);
           }
           blinkOn=false;
         }
         timeOfLastBlinkChange = currentTime;
       }
       break;        
     
     default:
       break;        
    }       
    strip.show();
}
