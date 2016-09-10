/*
 * Powerup header file
 * The powerup is an object that can be picked up but not moved
 */
#ifndef Powerup_h // preprocessor commands to ensure
#define Powerup_h // single import of header and code file
#include "Arduino.h" // include arduino functions

class Powerup
{
  private:
      int x;
      int y;
      int screenWidth;
      int screenHeight;
   public:
      Powerup(int x_ = 0, int y_ = 0, int screenWidth_ = 8, int screenHeight_ = 8);
      bool checkCollision(int checkX, int checkY);
      int getX();
      int getY();
      ~Powerup();
};
#endif
