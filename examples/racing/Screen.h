/*
 * Screen header file
 * Handles screen related functions
 */
#ifndef Screen_h // preprocessor commands to ensure
#define Screen_h // single import of header and code file
#include "Arduino.h" // include arduino functions

class Screen
{
  private:
    //Pin connected to ST_CP of 74HC595
    int latchPin;
    //Pin connected to SH_CP of 74HC595
    int clockPin;
    //Pin connected to DS of 74HC595
    int dataPin;
    int mapping[16] = {/*columns*/15,14,10,2,9,4,5,12,/*rows*/8,13,0,11,7,1,6,3};
    int smileMatrix[8][8] = {
      {1,0,0,0,0,0,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,1,0,0,1,0,0},
      {1,0,0,0,0,0,0,1},
      {0,1,0,0,0,0,1,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0}
    };


    int blankMatrix[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
    };
    int testMatrix[8][8] = {
      {1,1,1,1,1,1,1,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,1,1,1,1,1,1,1}
    };

    int anim1Matrix[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
    };

    int anim2Matrix[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,1,1,1,1,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,1,1,1,1,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
    };

    int anim3Matrix[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
    };

    int anim4Matrix[8][8] = {
      {1,1,1,1,1,1,1,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,0,0,0,0,0,0,1},
      {1,1,1,1,1,1,1,1}
    };
    bool animOn;
    int * convertArrayAndDraw(int data[16]);
    void shiftOutArray(int myDataPin, int myClockPin, int* writeData);
  public:
    Screen(int latchPin_ = 8, int clockPin_ = 12, int dataPin = 11);
    void playAnimation();
    void loop();
    void drawMatrix(int matrix[8][8], int displayTime = 1);
    void drawPoint(int x, int y);
    bool animationOn();
};
#endif
