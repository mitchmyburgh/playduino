/*
 * Snake header file
 * The The snake is a linked list of Entities
 */
#ifndef Snake_h // preprocessor commands to ensure
#define Snake_h // single import of header and code file
#include "Arduino.h" // include arduino functions
#include "Entity.h"

class Snake
{
  private:
      Entity* node; // each snake has an entity as a node
      Snake* next; // the next snake in the linked list
      int moveX = 0; // the previous x move from propogating down the snake 
      int moveY = 0; // the previous y move for propogation down the snake
      bool collidable = false; // is the current snake allowed to collide with other snakes
   public:
      Snake(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);
      void move(int moveX = 0, int moveY = 0);
      void addNode();
      Snake* getNext();
      Entity* getNode();
      void addNext();
      bool checkCollision();
      void setCollidable(bool col);
      bool getCollidable();
      // destructor : destroy objects at end of runtime
      ~Snake();
};
#endif
