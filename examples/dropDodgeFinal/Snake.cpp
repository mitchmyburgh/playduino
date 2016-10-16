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
  //hold the previous move for propogation down the snake
  moveX = 0;
  moveY = 0;
  next = NULL;
}

/**
 * Add node to the snake
 * Adds teh node to the end of the snake and at the same position as the last node
 */
void Snake::addNode() {
  Snake* currentNode = this;
  while (currentNode->getNext() != NULL){
    currentNode = currentNode->getNext();
  }
  currentNode->addNext();
}

/**
 * Get teh ndoe for the current snake part
 */
Entity* Snake::getNode() {
  return node;
}

/**
 * Get the next snake part
 */
Snake* Snake::getNext() {
  return next;
}

/**
 * Add a node after the current one (in the same position)
 */
void Snake::addNext() {
  next = new Snake(node->getX(), node->getY());
  next->setCollidable(false); //the node is currently under another node so dont make it collidable
}

/**
 * Move the snake
 * int x_ - the number of pixels in the x-direction to move
 * int y_ - the number of pixels in the y direction to move
 */
void Snake::move(int x_, int y_){
  if (x_ == 0 && y_ == 0){ //continue moving in the same direction
    x_ = moveX;
    y_ = moveY;
  } else {
    collidable = true;  //the last pixel becomes collidable when it is no longer covered by a pixel
  }
  if (moveX != 0 || moveY != 0){
    node->move(x_, y_);
  }
  if (this->getNext() != NULL){
    this->getNext()->move(moveX, moveY); //propogate movement down the linked list
  }
  //store current movement for next loop
  moveX = x_; 
  moveY = y_;
}

/**
 * Check collision of the snake with itsself
 */
bool Snake::checkCollision() {
  int prevX = this->getNode()->getX();
  int prevY = this->getNode()->getY();
  Snake* currentNode = this->getNext();
  while (currentNode != NULL) { //loop over nodes
     if (currentNode->getNode()->checkCollision(prevX, prevY) && currentNode->getCollidable()){
       return true;
     }
     currentNode = currentNode->getNext();
  }
  return false;
}

/**
 * Get if the current node is able to collide
 */
bool Snake::getCollidable(){
  return collidable;
}

/**
 * Set if the current node is able to collide
 */
void Snake::setCollidable(bool col){
  collidable = col;
}
 /*
  * Destructor
  */
Snake::~Snake(void){
  delete this->node;
  delete this->next; // delete single object pointer
}
