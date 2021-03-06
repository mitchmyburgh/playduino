/**
 * Screen class
 * Handles screen related functions
 */
 #include "Screen.h"
 #include "Arduino.h"
 #include "lib/elapsedMillis/elapsedMillis.h"

 elapsedMillis timeElapsedScreen; // timer

/**
 * Constructor
 * int x_ - the x position of the entity
 * int y_ - the y position of the entity
 * int screenWidth_ - the number of pixels in the screen's width
 * int screenHeight_ - the number of pixels in the screen's height
 */
Screen::Screen(int latchPin_, int clockPin_, int dataPin_) {
  latchPin = latchPin_;
  clockPin = clockPin_;
  dataPin = dataPin_;
  animOn = true;
  pinMode(latchPin, OUTPUT);
}
/**
 * Play the default animation
 */
void Screen::playAnimation() {
  animOn = true;
}

bool Screen::animationOn() {
  return animOn;
}

/**
 * Loop for the screen - should be called from the main Arduino loop
 */
void Screen::loop() {
  if (animOn){
    drawMatrix(blankMatrix, 400);
    drawMatrix(anim1Matrix, 400);
    drawMatrix(anim2Matrix, 400);
    drawMatrix(anim3Matrix, 400);
    drawMatrix(anim4Matrix, 400);
    drawMatrix(anim3Matrix, 400);
    drawMatrix(anim2Matrix, 400);
    drawMatrix(anim1Matrix, 400);
    drawMatrix(blankMatrix, 400);
    animOn = false;
  }
}

/**
 * Draw a matrix
 * int matrix[8][8] - 8x8 matrix representing the pixels to display
 * int displayTime - how long to display the matrix for
 */
void Screen::drawMatrix(int matrix[8][8], int displayTime) {
  timeElapsedScreen = 0;
  while(timeElapsedScreen < displayTime){
    int writeData[] = {/*columns*/0,0,0,0,0,0,0,0,/*rows*/0,0,0,0,0,0,0,0};
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 16; j++){
        writeData[j] = 0;
      }
      for (int j = 0; j < 8; j++){
        if (matrix[j][i] == 1) {
          writeData[i+8] = 1;
          writeData[j] = 0;
        } else {
          writeData[j] = 1;
        }
      }
      convertArrayAndDraw(writeData);
    }
  }
  timeElapsedScreen = 0;
}

/**
 * Draw point on the screen - successive calls can be used to create an image
 * int x - the x coordinate of the point
 * int y - the y coordinate of the point
 */
void Screen::drawPoint(int x, int y) {
  int writeData[] = {/*columns*/0,0,0,0,0,0,0,0,/*rows*/0,0,0,0,0,0,0,0};
  // intersection of on off column and on row will switch the light on
    for (int i = 0; i < 8; i++){
      if (y == i) {
        writeData[i] = 0;
      } else {
        writeData[i] = 1;
      }
      if (x == i) {
        writeData[i+8] = 1;
      } else {
        writeData[i+8] = 0;
      }
    }
    convertArrayAndDraw(writeData);
    delay(1);
}

/**
 * Converts an array of points to the mapping used by the screen's pins
 * where data[0] to data[7] represents the rows 0 to 7
 * and data[8] to data[15] represents teh columns 0 to 7
 * int data[16] - the array of rows and columns and their off and on states
 */
int * Screen::convertArrayAndDraw(int data[16]) {
  int drawData[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (int i = 0; i < 16; i++) {
      drawData[mapping[i]] = data[i];
  }
  digitalWrite(latchPin, 0);
  shiftOutArray(dataPin, clockPin, drawData);
  digitalWrite(latchPin, 1);
  delay(1);
}

/**
 * Writes an array pointer to the screen, must be converted by convertArray First
 * int myDataPin - the data pin for the shift register
 * int myClockPin - the clock pin for the shift register
 * int * writeData - the converted data showing the rows and columns to write to
 */
void Screen::shiftOutArray(int myDataPin, int myClockPin, int* writeData) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  for (i=0; i<16; i++)  {
    digitalWrite(myClockPin, 0);

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, *(writeData+i));
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}

/**
 * Destroy the screen
 */
Screen::~Screen(void) {

}
