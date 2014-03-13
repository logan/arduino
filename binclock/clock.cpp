#include "Arduino.h"

#include "clock.h"

Clock::Clock() : h(0), m(0), s(0), timer(1000) { }

void Clock::loop() {
    if (timer.tick()) {
        incr();
    }
}

void Clock::incrHour() {
    timer.sync(1000);
    h = h % 12 + 1;
}

void Clock::incrMinute() {
    timer.sync(1000);
    m = (m + 1) % 60;
}

void Clock::incr() {
    if (++s >= 60) {
        s = 0;
        if (++m >= 60) {
            m = 0;
            h = h % 12 + 1;
        }
    }

    if (h > 9) {
        Serial.print(h / 10);
    } else {
        Serial.print(' ');
    }
    Serial.print(h % 10);
    Serial.print(':');
    Serial.print(m / 10);
    Serial.print(m % 10);
    Serial.print(':');
    Serial.print(s / 10);
    Serial.println(s % 10);
}
