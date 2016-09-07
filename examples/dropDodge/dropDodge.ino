#include "Screen.h"
#include "Entity.h"
#include "Enemy.h"
#include "Button.h"
#include "lib/elapsedMillis/elapsedMillis.h"

Screen myScreen;
Entity player;
Button upButton;
Button downButton;
Button leftButton;
Button rightButton;

Enemy enemies[8];

elapsedMillis timeElapsed;

void setup() {
  // put your setup code here, to run once
  myScreen = Screen();
  player = Entity(7,1);
  upButton = Button(7);
  downButton = Button(6);
  leftButton = Button(5);
  rightButton = Button(4);
  randomSeed(analogRead(0));
  for (int i = 0; i < 8; i++) {
    enemies[i] = Enemy(floor(random(8)), -1*floor(random(8)));
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  myScreen.loop();
  if(!myScreen.animationOn()) {
    upButton.loop();
    downButton.loop();
    leftButton.loop();
    rightButton.loop();
    if (upButton.isPressedOnce()) {
      player.move(0, -1);
    }
    if (downButton.isPressedOnce()) {
      player.move(0, +1);
    }
    if (leftButton.isPressedOnce()) {
      player.move(-1, 0);
    }
    if (rightButton.isPressedOnce()) {
      player.move(+1, 0);
    }
    myScreen.drawPoint(player.getX(), player.getY());
    for (int i = 0; i < 8; i++) {
      myScreen.drawPoint(enemies[i].getX(), enemies[i].getY());
      if (player.checkCollision(enemies[i].getX(), enemies[i].getY())){
        for (int i = 0; i < 8; i++) {
          enemies[i] = Enemy(floor(random(8)), -1*floor(random(8)));
        }
        myScreen.playAnimation();
      }
    }
    if (timeElapsed > 1000){
      for (int i = 0; i < 8; i++) {
        enemies[i].move(0, +1);
      }
      timeElapsed = 0;
    }
  }
}
