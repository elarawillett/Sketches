/* Thanksgiving
 Modified 8 November 2014
 For Best Mom Ever
 */
int buzzerPin = 5;
int toneDuration = 4000;
int pauseDuration = 300;
float noteG5 = 783.991;
float noteF5 = 698.456;
float noteE5 = 659.255;
float noteD5 = 587.330;
float noteC5 = 523.251;
float noteB4 = 493.883;
float noteBflat4 = 466.16;
float noteA4 = 440;
float noteG4 = 391.995;
float noteF4 = 349.23;
float noteE4 = 329.63;
float noteC4 = 261.63;
int half = toneDuration/2;
int quarter = toneDuration/4;
int eighth = toneDuration/8;
int dottedQuarter = 3*toneDuration/8;

void play(float pitch, int length){
  tone(buzzerPin, pitch, length);
  delay(length);
}

// the setup function runs once when you press reset or power the board
void setup() {
    //Line 1
    play(noteC4,eighth);
    play(noteC4,eighth);
    
    play(noteF4, quarter);
    play(noteF4, eighth);
    play(noteG4, eighth);
    play(noteA4, eighth);
    play(noteF4, eighth);
    play(noteA4, eighth);
    play(noteBflat4, eighth);
    
    play(noteC5, quarter);
    play(noteC5, eighth);
    play(noteBflat4, eighth);
    play(noteA4, quarter);
    play(noteG4, eighth);
    play(noteF4, eighth);
    
    //Line 2
    play(noteG4,quarter);
    play(noteG4,quarter);
    play(noteG4,quarter);
    play(noteF4,quarter);
    
    play(noteG4,eighth);
    play(noteA4,eighth);
    play(noteG4,eighth);
    play(noteE4,eighth);
    play(noteC4,quarter);
    play(noteC4,quarter);
    
    play(noteF4,eighth);
    play(noteE4,eighth);
    play(noteF4,eighth);
    play(noteG4,eighth);
    play(noteA4,quarter);
    play(noteG4,eighth);
    play(noteG4,eighth);
    
    //Line 3
    play(noteA4,quarter);
    play(noteBflat4,quarter);
    play(noteC5,quarter);
    play(noteA4,quarter);

    play(noteG4,quarter);
    play(noteG4,eighth);
    play(noteG4,eighth);
    play(noteA4,quarter);
    play(noteA4,eighth);
    play(noteG4,eighth);

    play(noteF4,quarter);
    play(noteF4,eighth);
    play(noteF4,eighth);
    play(noteF4,half);
    
    //Line 4
    play(noteC5,half);
    play(noteA4,dottedQuarter);
    play(noteG4,eighth);
    
    play(noteA4,eighth);
    play(noteBflat4,eighth);
    play(noteA4,eighth);
    play(noteG4,eighth);
    play(noteF4,dottedQuarter);
    play(noteG4,eighth);
    
    play(noteA4,quarter);
    play(noteA4,eighth);
    play(noteBflat4,eighth);
    play(noteC5,quarter);
    play(noteA4,quarter);
    
    play(noteG4,quarter);
    play(noteG4,eighth);
    play(noteA4,eighth);
    play(noteG4,quarter);
    play(noteC4,quarter);
    
    //Line 5
    play(noteF4,half);
    play(noteF4,dottedQuarter);
    play(noteG4,eighth);
    
    play(noteA4,quarter);
    play(noteA4,eighth);
    play(noteBflat4,eighth);
    play(noteC5,quarter);
    play(noteBflat4,eighth);
    play(noteA4,eighth);
    
    play(noteG4,quarter);
    play(noteG4,quarter);
    play(noteA4,quarter);
    play(noteA4,eighth);
    play(noteG4,eighth);
    
    play(noteF4,quarter);
    play(noteF4,quarter);
    play(noteF4,half);
}

// the loop function runs over and over again forever
void loop() {
}
