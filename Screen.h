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
    int screenWidth;
    int screenHeight;
    int mapping[];
    int smileMatrix[8][8];
    int blankMatrix[8][8];
    int anim1Matrix[8][8];
    int anim2Matrix[8][8];
    int anim3Matrix[8][8];
    int anim4Matrix[8][8];
    bool animOn;
  public:
    Screen(int screenWidth_ = 8, int screenHeight_ = 8, int latchPin_ = 8, int clockPin_ = 12, int dataPin = 11);
    void playAnimation();
    void loop();
    void drawMatrix(int matrix[8][8], int displayTime);
    int * convertArrayAndDraw(int data[16]);
    void shiftOutArray(int myDataPin, int myClockPin, int* writeData);
};
#endif
