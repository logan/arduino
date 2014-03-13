#include "Arduino.h"

#include "button.h"

Button::Button(int pin) : pin(pin) { }

void Button::setup() {
    pinMode(pin, INPUT);
}

void Button::loop(int *state, unsigned long *ms) {
    unsigned long now = millis();
    int v = digitalRead(pin);
    if (this->state != v) {
        this->state = v;
        bounceStart = now;
    }
    *state = this->state;
    *ms = now - bounceStart;
}
