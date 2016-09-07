/*
 * Enemy header file
 * An Enemy
 */
 #include "Enemy.h"
 #include "Arduino.h"

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Enemy::Enemy(int x_, int y_, int screenWidth_ = 8, int screenHeight_ = 8) : Entity(x_, y_, screenWidth_, screenHeight_) {
  randomSeed(analogRead(0));
}

/**
 * Move the entity with screen wrap around
 * int moveX - the number of pixels to move in the X direction
 * int moveY - the number of pixels to move in the Y direction
 */
void Enemy::move(int moveX = 0, int moveY = 0) {
  x += moveX;
  y += moveY;
  if (y >= screenHeight) {
    setY(-1*floor(random(8)));
  }
  if (x >= screenWidth) {
    setX(floor(random(8)));
  }
}
