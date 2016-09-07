/*
 * Enemy header file
 * An Enemy
 */
#ifndef Enemy_h // preprocessor commands to ensure
#define Enemy_h // single import of header and code file
#include "Arduino.h" // include arduino functions
#include "Entity.h"

class Enemy : public Entity
{
   private:
   public:
      Enemy(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);
      void move(int moveX = 0, int moveY = 0);
};
#endif
