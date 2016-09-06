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
      int buttonPin;
      bool pressedOnce;
      bool pressed;
   public:
      Button(int buttonPin_);
      void loop();
      bool isPressed();
      bool isPressedOnce();
};
#endif
