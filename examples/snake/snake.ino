//imports
#include "Snake.h"
#include "Screen.h"
#include "Button.h"
#include "Powerup.h"
#include "lib/elapsedMillis/elapsedMillis.h"

//variables
Snake* snake;
Screen* screen;

Button* upButton;
Button* downButton;
Button* leftButton;
Button* rightButton;

Powerup* powerup;

elapsedMillis timeElapsed;

int score = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  snake = new Snake(4,7); //initislise the snake
  screen = new Screen(); //initialise the screen
  upButton = new Button(7); //initialise the up button on pin 7
  downButton = new Button(6); //initialise the down button on pin 7
  leftButton = new Button(5); //initialise the left button on pin 5
  rightButton = new Button(4); //initialise the right button on pin 4
  randomSeed(analogRead(0)); //initialise random
  powerup = new Powerup((int)floor(random(8)), (int)floor(random(8))); //create the powerup at a ranom position
}

void loop() {
  // put your main code here, to run repeatedly:
  screen->loop(); //loop the screen
  if(!screen->animationOn()) { //while the animation is not running - play the game
    // loop teh buttons
    upButton->loop();
    downButton->loop();
    leftButton->loop();
    rightButton->loop();
    //handle button presses
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
    //draw the powerup
    screen->drawPoint(powerup->getX(), powerup->getY());
    //draw the snake
    Snake* currentNode = snake;
    do{
     screen->drawPoint(currentNode->getNode()->getX(), currentNode->getNode()->getY());
     currentNode = currentNode->getNext();
    } while (currentNode != NULL);
    //move the snake so it moves without pressing buttons
    if (timeElapsed > 500){
      snake->move();
      timeElapsed = 0;
    }
    // check collision and end game
    if (snake->checkCollision()){
      Serial.println("Well done! You scored:");
      Serial.println(score);
      snake = new Snake(4,7); //reset teh snake
      powerup = new Powerup((int)floor(random(8)), (int)floor(random(8))); //reset the powerup
      screen->playAnimation(); // play the animation
    }
    //check collision with powerup 
    if (powerup->checkCollision(snake->getNode()->getX(), snake->getNode()->getY())){
      snake->addNode(); //add node to tail of snake
      powerup = new Powerup((int)floor(random(8)), (int)floor(random(8))); //reset powerup position
      score++;
    }
  }
}
