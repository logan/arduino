#include "Arduino.h"

#include "timer.h"

Timer::Timer(unsigned long interval) {
    sync(interval);
}

void Timer::sync(unsigned long interval) {
    this->interval = interval;
    base = millis();
    curModulus = baseModulus = (int) (base % interval);
}

bool Timer::tick(unsigned long *duration) {
    unsigned long now = millis();
    int nextModulus = (int) (now % interval);
    bool result;
    if (baseModulus == 0) {
        result = nextModulus < curModulus;
    } else {
        result = curModulus < baseModulus && nextModulus >= baseModulus;
    }
    curModulus = nextModulus;
    if (duration != NULL) {
        *duration = now - base;
    }
    return result;
}
