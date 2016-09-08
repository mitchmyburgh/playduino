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
  node->move(x_, y_);
  moveX = x_;
  moveY = y_;
  if (this->getNext() != NULL){
    this->getNext()->move(moveX, moveY);
  }
}

int Snake::test() {
  return 5;
}
