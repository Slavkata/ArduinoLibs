#ifdef ColorMode_h
#define ColorMode_h

#include "Arduino.h"

class ColorMode {
  public:
    ColorMode(int redPin, int greenPin, int bluePin);
    void displayRainbow();
    void displayColor(int color);
    void printColors(int valueR, int valueG, int valueB);
  private:
    enum transitoin;
    int _redPin, _bluePin, _greenPin, _currentTransition, r = 0, g = 0, b = 0;
}

#endif
