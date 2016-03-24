const int buttonPin = 13;
const int ledPin = 3;
const int debounce = 200;

int state = 1;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  //Serial.begin(9600);
}

void loop(){

  if(digitalRead(buttonPin)==LOW){
    state = 1 - state;
  }
  
  digitalWrite(ledPin, state);
  //Serial.println(state);
  delay(debounce);
}
