//imports
#include "Screen.h"
#include "Entity.h"
#include "Enemy.h"
#include "Button.h"
#include "lib/elapsedMillis/elapsedMillis.h"

// variables
Screen* screen;
Entity* player;
Button* leftButton;
Button* rightButton;

Enemy *enemies[8];

elapsedMillis timeElapsed;

int score = 0;

// setup function
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600); // for printing
  randomSeed(analogRead(0)); // for random number generation
  screen = new Screen();
  leftButton = new Button(6); // bottom left button
  rightButton = new Button(4); // bottom right button

  // generate the enemies
  for (int i = 0; i < 8; i++) {
    enemies[i] = new Enemy((int)floor(random(8)), (int)(-1*floor(random(8))));
  }

  //? create the player
  player = new Entity(4,7);
}

// loop function - called continously
void loop() {
  screen->loop();
  if(!screen->animationOn()) {
    leftButton->loop();
    rightButton->loop();
    if (leftButton->isPressedOnce()) {
      //? move the player
      player->move(-1, 0);
    }
    if (rightButton->isPressedOnce()) {
      //? move the player
      player->move(1, 0);
    }
    screen->drawPoint(player->getX(), player->getY());
    for (int i = 0; i < 8; i++) {
      //? draw the enemies
      screen->drawPoint(enemies[i]->getX(), enemies[i]->getY());
      if (player->checkCollision(enemies[i]->getX(), enemies[i]->getY())){ // game ends
        for (int i = 0; i < 8; i++) {
          enemies[i] = new Enemy((int)floor(random(8)), (int)(-1*floor(random(8))));
        }
        Serial.println("Well done! You scored:");
        Serial.println(score);
        score = 0;
        //? reset the player's position
        player->setX(4);
        player->setY(7);
        screen->playAnimation();
        break;
      }
    }
    // fires every second
    if (timeElapsed > 1000){
      score++;
      //? move the enemies
      for (int i = 0; i < 8; i++) {
          enemies[i]->move(0, 1);
        }
      timeElapsed = 0;
    }
  } 
}
