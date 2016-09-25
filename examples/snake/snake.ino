#include "Snake.h"
#include "Screen.h"
#include "Button.h"
#include "Powerup.h"
#include "lib/elapsedMillis/elapsedMillis.h"

Snake* snake;
Screen* screen;

Button* upButton;
Button* downButton;
Button* leftButton;
Button* rightButton;

Powerup* powerup;

elapsedMillis timeElapsed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  snake = new Snake(4,7);
  screen = new Screen();
  upButton = new Button(7);
  downButton = new Button(6);
  leftButton = new Button(5);
  rightButton = new Button(4);
  randomSeed(analogRead(0));
  powerup = new Powerup((int)floor(random(8)), (int)floor(random(8)));
}

void loop() {
  // put your main code here, to run repeatedly:
  screen->loop();
  if(!screen->animationOn()) {
    upButton->loop();
    downButton->loop();
    leftButton->loop();
    rightButton->loop();
    if (upButton->isPressedOnce()) {
      snake->move(0, -1);
    }
    if (downButton->isPressedOnce()) {
      snake->move(0, +1);
    }
    if (leftButton->isPressedOnce()) {
      snake->move(-1, 0);
    }
    if (rightButton->isPressedOnce()) {
      snake->move(+1, 0);
    }
    screen->drawPoint(powerup->getX(), powerup->getY());
    Snake* currentNode = snake;
    do{
     screen->drawPoint(currentNode->getNode()->getX(), currentNode->getNode()->getY());
     currentNode = currentNode->getNext();
    } while (currentNode != NULL);
    if (timeElapsed > 500){
      snake->move();
      timeElapsed = 0;
    }
    if (snake->checkCollision()){
      //delete snake;
      //delete powerup;
      snake = new Snake(4,7);
      powerup = new Powerup((int)floor(random(8)), (int)floor(random(8)));
      screen->playAnimation();
    }
    if (powerup->checkCollision(snake->getNode()->getX(), snake->getNode()->getY())){
      snake->addNode();
      //delete powerup;
      powerup = new Powerup((int)floor(random(8)), (int)floor(random(8)));
    }
  }
}
