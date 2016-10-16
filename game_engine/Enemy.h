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
   public:
      Enemy();
      Enemy(int x_, int y_);
      Enemy(int x_, int y_, int screenWidth_, int screenHeight_);
      void move(int moveX = 0, int moveY = 0);
      // destructor : destroy objects at end of runtime
      ~Enemy();
};
#endif
