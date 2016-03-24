#include <DallasTemperature.h>
#include <OneWire.h>

// Data wire is plugged into pin 6 on the Arduino
#define ONE_WIRE_BUS 6
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/*
YoBot
 modified 18 October 2014
 
 
 */
int buzzerPin = 12;
int toneDuration = 500;
int toneFrequencyHigh = 100;
int toneFrequencyLow = 500;
int pauseDuration = 5000;
int lowTemp = 116;
int highTemp = 179;
bool toneOn = true;
bool onTheWayUp = true;
bool finished = false;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // Start up the library
  sensors.begin(); 
   pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  if (!finished){
    
    digitalWrite(13,HIGH);
    // get temperature
    sensors.requestTemperatures(); 
    float inputTemp = sensors.getTempFByIndex(0);
    Serial.println(inputTemp);
  
  //at high temp
  if(onTheWayUp && (inputTemp>highTemp)){
      for (int i = 0; i< 5; i++){
        tone(buzzerPin, toneFrequencyHigh, toneDuration);
        delay(pauseDuration); 
      }
      onTheWayUp = false;
    }
  
  // at low temp
    if(!onTheWayUp && (inputTemp<lowTemp)){ 

      for (int i = 0; i< 5; i++){
        tone(buzzerPin, toneFrequencyHigh, toneDuration);
        delay(pauseDuration);  
      }
      finished = true;
      digitalWrite(13,LOW);
    }
    
  }
}

