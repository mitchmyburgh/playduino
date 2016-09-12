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
      int x; // the x position of the powerup
      int y; // the y position of the powerup
   public:
      Powerup(int x_ = 0, int y_ = 0);
      bool checkCollision(int checkX, int checkY);
      int getX();
      int getY();
      ~Powerup();
};
#endif
