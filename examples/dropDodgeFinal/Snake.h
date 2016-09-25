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
      Entity* node;
      Snake* next;
      int moveX = 0;
      int moveY = 0;
      bool collidable = false;
   public:
      Snake(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);

      // destructor : destroy objects at end of runtime
      ~Snake();

      void move(int moveX = 0, int moveY = 0);
      void addNode();
      Snake* getNext();
      Entity* getNode();
      void addNext();
      bool checkCollision();
      void setCollidable(bool col);
      bool getCollidable();
      //bool checkCollision(int checkX, int checkY);
};
#endif
