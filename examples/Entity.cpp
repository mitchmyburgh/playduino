/**
 * Entity class
 * The entity can be used to represent a player or enemy - anything that moves independently
 */
 #include "Entity.h"
 #include "Arduino.h"
/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Entity::Entity(int x_, int y_, int screenWidth_, int screenHeight_) {
  x = x_;
  y = y_;
  screenWidth = screenWidth_;
  screenHeight = screenHeight_;
}

/**
 * Move the entity with screen wrap around
 * int moveX - the number of pixels to move in the X direction
 * int moveY - the number of pixels to move in the Y direction
 */
void Entity::move(int moveX, int moveY) {
  x = abs(screenWidth+(x+moveX))%screenWidth;
  y = abs(screenHeight+(y+moveY))%screenHeight;
}

/**
 * checkCollision for point with entity
 * int checkX - x value of point to checkX
 * int checkY - the y vlaue of point to checkY
 * return bool - does the point collide with entity
 */
bool Entity::checkCollision(int checkX, int checkY) {
  return (checkX == x && checkY == y);
}

/**
 * getX - returns the x value of the entity
 * return int x
 */
int Entity::getX() {
  return x;
}

/**
 * getY - returns the y value of the entity
 * return int y
 */
int Entity::getY() {
  return y;
}

/**
 * setX - set the x position of the Entity
 * int x_ - the x position
 */
void Entity::setX(int x_) {
  x = x_;
}

/**
 * setY - set the y position of the Entity
 * int y_ - the y position
 */
void Entity::setY(int y_) {
  y = y_;
}
