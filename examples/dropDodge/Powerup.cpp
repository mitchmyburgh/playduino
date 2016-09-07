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
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Powerup::Powerup(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8) {
  x = x_;
  y = y_;
  screenWidth = screenWidth_;
  screenHeight = screenHeight_;
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
