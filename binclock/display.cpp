#include "Arduino.h"

#include "display.h"

Display::Display(int *pins) : pins(pins) { }

void Display::setup() {
    for (int i = 0; i < 10; i++) {
        pinMode(pins[i], OUTPUT);
    }
}

void Display::set(int encoded) {
    int mask = 1;
    for (int i = 0; i < 10; i++) {
        digitalWrite(pins[i], (encoded & (mask<<i)) ? HIGH : LOW);
    }
}
