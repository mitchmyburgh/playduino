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
 * int width_ - the width of the entity
 * int height_ - the height of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Entity::Entity(int x_ = 0, int y_ = 0, int width_ = 1, int height_ = 1, int screenWidth_ = 8, int screenHeight_ = 8) {
  x = x_;
  y = y_;
  width = width_;
  height = height_;
  screenWidth = screenWidth_;
  screenHeight = screenHeight_;
}

/**
 * Move the entity with screen wrap around
 * int moveX - the number of pixels to move in the X direction
 * int moveY - the number of pixels to move in the Y direction
 */
void Entity::move(int moveX = 0, int moveY = 0) {
  x = abs(screenWidth+(x+moveX))%screenWidth;
  y = abs(screenHeight+(y+moveY))%screenHeight;
}

/**
 * Execuet loop coommands
 */
void Entity::loop() {

}

/**
 * checkCollision for point with entity
 * int checkX - x value of point to checkX
 * int checkY - the y vlaue of point to checkY
 * return bool - does the point collide with entity
 */
bool checkCollision(int checkX, int checkY) {

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
 * getWidth - returns the width value of the entity
 * return int width
 */
int Entity::getWidth() {
  return width;
}

/**
 * getHeight - returns the height value of the entity
 * return int height
 */
int Entity::getHeight() {
  return height;
}
