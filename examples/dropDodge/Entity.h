/*
 * Entity header file
 * The entity can be used to represent a player or enemy - anything that moves independently
 */
#ifndef Entity_h // preprocessor commands to ensure
#define Entity_h // single import of header and code file
#include "Arduino.h" // include arduino functions

class Entity
{
   private:
      int x;
      int y;
      int screenWidth;
      int screenHeight;
   public:
      Entity(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);
      void move(int moveX = 0, int moveY = 0);
      void loop();
      bool checkCollision(int checkX, int checkY);
      int getX();
      int getY();
      int getWidth();
      int getHeight();
};
#endif
