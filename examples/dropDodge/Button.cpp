/*
 * Button header file
 * The button
 */
 #include "Button.h"
 #include "Arduino.h"

/**
 * Constructor
 * int buttonPin_ - the Pin that the button is connected to
 */
Button::Button(int buttonPin_) {
  buttonPin = buttonPin_;
}
