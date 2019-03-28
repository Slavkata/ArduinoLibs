#include "Arduino.h"
#include "ColorMode.h"

enum transition {
  initial = 0,
  red_blue = 1,
  bl = 2,
  blue_green = 3,
  grn = 4,
  green_red = 5,
  rd = 6
};

ColorMode::ColorMode(int redPin, int greenPin, int bluePin) {
  _redPin = redPin;
  _greenPin = greenPin;
  _bluePin = bluePin;
  _currentTransition = 0;
}

ColorMode::displayRainbow() {
  switch(currentTransition) {
    case initial:
      // checking if red color is reached
      if(r == 255) {
        // displays the pure red and proceed to the next state
        printColors();
        currentTransition = red_blue;
      }
      else {
        // display the current color and increment the red intensity
        printColors();
        r++;
      }
      break;
    case red_blue:
      // checking if red+blue is reached
      if(b == 255) {
        // display the combination of 255R and 255B and proceed to the next state
        printColors();
        currentTransition = bl; 
      }
      else {
        // display the color and increment the blue intensity
        printColors();
        b++;
      }
      break;
    case bl:
      // check if the pure blue color is reached
      if(r == 0) {
        // display the pure blue and proceed to the next state
        printColors();
        currentTransition = blue_green;
      }
      else {
        // display the current color and decrement the red intensity
        printColors();
        r--;
      }
      break;
    case blue_green:
      // check if the blue+green color is reached
      if(g == 255) {
        // display the 255B + 255G color and proceed to the next state
        printColors();
        currentTransition = grn;
      }
      else {
        // display the current color and increment the green intensity
        printColors();
        g++;
      }
      break;
    case grn:
      // check if the pure green color is reached
      if(b == 0) {
        // display the pure green color and proceed to the next state
        printColors();
        currentTransition = green_red;
      }
      else {
        // display the current color and decrement the blue intensity
        printColors();
        b--;
      }
      break;
    case green_red:
      // check if the the red+green color is reached
      if(r == 255) {
        // display the 255R + 255G color and proceed to the next state
        printColors();
        currentTransition = rd;
      }
      else {
        // display the current color and increment the red intensity
        printColors();
        r++;
      }
      break;
    case rd:
      // check if the pure red color is reached
      if(g == 0) {
        // display the pure red color and proceed to the next state
        printColors();
        currentTransition = red_blue;
      }
      else {
        // display the current color and decrement the green intensity
        printColors();
        g--;
      }
      break;
  }
}

ColorMode::printColors(int valueR = r, int valueG = g, int valueB = b) {
  analogWrite(redPin, valueR);
  analogWrite(bluePin, valueB);
  analogWrite(greenPin, valueG);
}

ColorMode::displayColor(int color) {
  switch (color) {
    case red:
      printColors(255, 0, 0);
      break;
    case blue:
      printColors(0, 0, 255);
      break;
    case green:
      printColors(0, 255, 0);
      break;
    case cyan:
      printColors(0, 255, 255);
      break;
    case magenta:
      printColors(255, 0, 255);
      break;
    case yellow:
      printColors(255, 255, 0);
      break;
  }
}
