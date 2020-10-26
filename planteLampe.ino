#include "FastLED.h"

const int led1 = 3;
const int led2 = 4;
const int button = 5;
const int antLeds = 9;
const int fotoSensor = A0;

boolean lysPaa = true;
int sensorVerdi = 0;

CRGB LED1[antLeds];
CRGB LED2[antLeds];

CHSV av = CHSV(0, 0, 0);
CHSV lilla = CHSV(192, 255, 220);
  CHSV svakLilla = CHSV(192, 230, 50);


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, led1>(LED1, antLeds);
  FastLED.addLeds<NEOPIXEL, led2>(LED2, antLeds);
  pinMode(button, INPUT);

  
}

void loop() {
  sensorVerdi = analogRead(fotoSensor);
  Serial.println(sensorVerdi);
  if(sensorVerdi < 500){
    allePaa();
    
  }
  else{
    alleAv();
  }
  
}

void lysBryter(){
  
  if(lysPaa){
    alleAv();
  }
  else if(!(lysPaa)){
    allePaa();
  }
}

void allePaa(){
  for(int x = 0; x < antLeds; x++){
    LED1[x] = lilla;
    LED2[x] = lilla;
  }
  lysPaa = true;
  FastLED.show();
}

void alleAv(){
  for(int x = 0; x < antLeds; x++){
    LED1[x] = av;
    LED2[x] = av;
  }
  lysPaa = false;
  FastLED.show();
}
