#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "timer.h"

class Button;
class Clock;
class Display;

class Controller {
public:
    Controller(Button *b1, Button *b2, Clock *clock, Display *display);

    void setup();
    void loop();

private:
    Button *b1, *b2;
    Clock *clock;
    Display *display;

    Timer timer;
    int mode;
    bool incrementing;
    bool b1Released;

    void incr();
    int encode();
};

#endif
