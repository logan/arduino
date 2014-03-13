#ifndef CLOCK_H

#define CLOCK_H

#include "timer.h"

class Clock {
public:
    Clock();

    void loop();
    void incrHour();
    void incrMinute();

    int h, m, s;

private:
    Timer timer;

    void incr();
};

#endif
