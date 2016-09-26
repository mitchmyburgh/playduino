/*
 * Button header file
 * The button
 */
#ifndef Button_h // preprocessor commands to ensure
#define Button_h // single import of header and code file
#include "Arduino.h" // include arduino functions

class Button
{
   private:
     int buttonPin; // the pin the button is connected to
     bool pressedOnce; // is true when only immediately after the button has been pressed down after relese
     bool pressed; // is the button currently down
     bool buttonPressed = false; //internal variable for dealing with pressedOnce
   public:
      Button(int buttonPin_ = 0);
      void loop();
      bool isPressed();
      bool isPressedOnce();
};
#endif
