#include "Screen.h"
#include "Entity.h"
#include "Enemy.h"
#include "Button.h"
#include "Snake.h"
#include "lib/elapsedMillis/elapsedMillis.h"

Screen* screen;
Entity* player;
Button* upButton;
Button* downButton;
Button* leftButton;
Button* rightButton;
Snake* snake;

Enemy *enemies[8];

elapsedMillis timeElapsed;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  screen = new Screen();
  player = new Entity(1,7);
  upButton =  new Button(7);
  downButton = new Button(6);
  leftButton = new Button(5);
  rightButton = new Button(4);
  randomSeed(analogRead(0));
  for (int i = 0; i < 8; i++) {
    enemies[i] = new Enemy((int)floor(random(8)), (int)(-1*floor(random(8))));
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  //leftButton.loop();
  //Serial.println(leftButton.isPressedOnce());

  screen->loop();
  if(!screen->animationOn()) {
    upButton->loop();
    downButton->loop();
    leftButton->loop();
    rightButton->loop();
    if (upButton->isPressedOnce()) {
      //Serial.println(rightButton.isPressedOnce());
      Serial.println("Up");
      player->move(0, -1);
    }
    if (downButton->isPressedOnce()) {
      //Serial.println(rightButton.isPressedOnce());
      Serial.println("Down");
      player->move(0, +1);
    }
    if (leftButton->isPressedOnce()) {
      //Serial.println(rightButton.isPressedOnce());
      Serial.println("left");
      player->move(-1, 0);
    }
    if (rightButton->isPressedOnce()) {
      //Serial.println(rightButton.isPressedOnce());
      Serial.println("right");
      player->move(+1, 0);
    }
    screen->drawPoint(player->getX(), player->getY());
    for (int i = 0; i < 8; i++) {
      screen->drawPoint(enemies[i]->getX(), enemies[i]->getY());
      if (player->checkCollision(enemies[i]->getX(), enemies[i]->getY())){
        for (int i = 0; i < 8; i++) {
          enemies[i] = new Enemy((int)floor(random(8)), (int)(-1*floor(random(8))));
        }
        screen->playAnimation();
      }
    }
    if (timeElapsed > 1000){
      for (int i = 0; i < 8; i++) {
        enemies[i]->move(0, +1);
      }
      timeElapsed = 0;
    }
  }
}
