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
Enemy::Enemy() : Entity(0, 0, 8, 8) {
  randomSeed(analogRead(0));
}

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Enemy::Enemy(int x_ = 0, int y_ = 0) : Entity(x_, y_, 8, 8) {
  randomSeed(analogRead(0));
}

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Enemy::Enemy(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8) : Entity(x_, y_, screenWidth_, screenHeight_) {
  randomSeed(analogRead(0));
}

/**
 * Move the entity with screen wrap around
 * int moveX - the number of pixels to move in the X direction
 * int moveY - the number of pixels to move in the Y direction
 */
void Enemy::move(int moveX, int moveY) {
  x += moveX;
  y += moveY;
  if (y >= screenHeight) {
    setY((int)(-1*floor(random(8))));
    setX((int)floor(random(8)));
  }
  if (x >= screenWidth) {
    setY((int)(-1*floor(random(8))));
    setX((int)floor(random(8)));
  }
}

/**
 * Destroy the enemy
 */
Enemy::~Enemy(void) {

}
