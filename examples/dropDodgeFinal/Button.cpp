/*
 * Button class file
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
  pressed = false;
  pressedOnce = false;
  pinMode(buttonPin, INPUT);
}

/**
 * Loop code for the button - must be places in the arduino loop
 */
void Button::loop() {
  if (digitalRead(buttonPin) == HIGH){ //button pressed
    pressed = true; // button is down
    pressedOnce = false; // this is false because the button is being held down
    if (!buttonPressed) { //if they button is being pressed for the first time we want to know that
      pressedOnce = true;
      buttonPressed = true;
    }
  } else {
    pressed = false; // button has been released
    if (buttonPressed) { // button has been released
      buttonPressed = false;
      pressedOnce = false;
    }
  }
}

/**
 * Returns if the button is currently being pressed
 * bool pressed - is the button being pressed
 */
bool Button::isPressed() {
  return pressed;
}

/**
 * Returns if the button is currently being pressed for the first time after being released
 * bool pressed - is the button being pressed
 */
bool Button::isPressedOnce() {
  return pressedOnce;
}

/**
 * Destroy the button
 */
Button::~Button(void) {

}
