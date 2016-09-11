#include "Screen.h"

Screen screen;

//int background[8][8];

int backgroundOptions[5][8] = {
  {1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1},
  {0,0,0,0,0,0,0,0},
  {1,0,0,1,1,0,0,1},
  {0,0,0,1,1,0,0,0}  
};

void setup() {
  Serial.begin(9600); //setup for printing
  randomSeed(analogRead(0)); //initialise random
  screen = Screen(); //handles the screen
  //construct the background
  /*for (int i = 0; i < sizeof(background); i++){
    int randomValue = (int)floor(random(sizeof(backgroundOptions)));
    for (int j = 0; j < sizeof(background[i]); j++){
      background[i][j] = backgroundOptions[randomValue][j]; 
    }
  }*/
}

void loop() {
  screen.loop();
  if(!screen.animationOn()) {
    for (int i = 0; i < 8; i++){
      int randomValue = (int)floor(random(sizeof(backgroundOptions)));
      for (int j = 0; j < 8; j++){
        if (backgroundOptions[randomValue][j] == 1){
          screen.drawPoint(i, j); 
        } 
      }
    }
  }
  //screen->drawMatrix(background, 200);
  Serial.println("Hello world");
}
