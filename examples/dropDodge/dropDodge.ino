#include "Screen.h"
#include "Entity.h"

Screen myScreen;
Entity player;
void setup() {
  // put your setup code here, to run once
  myScreen = Screen();
  player = Entity(3,4);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  myScreen.loop();
  if (!myScreen.animationOn()) {
    myScreen.drawPoint(player.getX(), player.getY());  
  }
}
