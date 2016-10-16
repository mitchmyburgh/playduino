/*
 * Entity header file
 * The entity can be used to represent a player or enemy - anything that moves independently
 */
#ifndef Entity_h // preprocessor commands to ensure
#define Entity_h // single import of header and code file
#include "Arduino.h" // include arduino functions

class Entity
{
   protected:
     int x; // the x position of the entity
     int y; // the y position of the entity
     int screenWidth; // the screen width in pixels
     int screenHeight; // the screen height in pixels
   public:
      Entity(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);
      void move(int moveX = 0, int moveY = 0);
      bool checkCollision(int checkX, int checkY);
      int getX();
      int getY();
      void setX(int x_);
      void setY(int y_);
      // destructor : destroy objects at end of runtime
      ~Entity();
};
#endif
