/*
 * Snake class file
 * The The snake is a linked list of Entities
 */
 #include "Snake.h"
 #include "Arduino.h"
 #include "Entity.h"

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Snake::Snake(int x_, int y_, int screenWidth_, int screenHeight_) {
  node = new Entity(x_, y_, screenWidth_, screenHeight_);
  moveX = 0;
  moveY = 0;
  next = NULL;
}

/**
 * Move the entity with screen wrap around
 */
void Snake::addNode() {
  Snake* currentNode = this;
  while (currentNode->getNext() != NULL){
    currentNode = currentNode->getNext();
  }
  currentNode->addNext();
}

Entity* Snake::getNode() {
  return node;
}

Snake* Snake::getNext() {
  return next;
}

void Snake::addNext() {
  next = new Snake(node->getX(), node->getY());
}

void Snake::move(int x_, int y_){
  if (x_ == 0 && y_ == 0){
    x_ = moveX;
    y_ = moveY;
  } else {
    collidable = true;
  }
  if (moveX != 0 || moveY != 0){
    node->move(x_, y_);
  }
  if (this->getNext() != NULL){
    this->getNext()->move(moveX, moveY);
  }
  moveX = x_;
  moveY = y_;
}

bool Snake::checkCollision() {
  int prevX = this->getNode()->getX();
  int prevY = this->getNode()->getY();
  Snake* currentNode = this->getNext();
  do{
     if (currentNode->getNode()->checkCollision(prevX, prevY) && currentNode->getCollidable()){
       return true;
     }
     currentNode = currentNode->getNext();
  } while (currentNode != NULL);
  return false;
}

bool Snake::getCollidable(){
  return collidable;
}

void Snake::setCollidable(bool col){
  collidable = col;
}
