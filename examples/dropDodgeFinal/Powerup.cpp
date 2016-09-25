/**
 * Powerup class
 * The entity can be used to represent a player or enemy - anything that moves independently
 */
 #include "Powerup.h"
 #include "Arduino.h"

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 */
Powerup::Powerup(int x_, int y_) {
  x = x_;
  y = y_;
}

/**
 * checkCollision for point with entity
 * int checkX - x value of point to checkX
 * int checkY - the y vlaue of point to checkY
 * return bool - does the point collide with entity
 */
bool Powerup::checkCollision(int checkX, int checkY) {
  return (checkX == x && checkY == y);
}

/**
 * getX - returns the x value of the entity
 * return int x
 */
int Powerup::getX() {
  return x;
}

/**
 * getY - returns the y value of the entity
 * return int y
 */
int Powerup::getY() {
  return y;
}

/**
 * Destroy the powerup
 */
Powerup::~Powerup() {

}
