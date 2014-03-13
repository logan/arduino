#include "Arduino.h"

#include "button.h"
#include "clock.h"
#include "controller.h"
#include "display.h"

static Timer debug(1000);

Controller::Controller(Button *b1, Button *b2, Clock *clock, Display *display)
    : b1(b1), b2(b2), clock(clock), display(display), timer(0), mode(0) {
}

void Controller::setup() {
    b1->setup();
    b2->setup();
    display->setup();
}

void Controller::loop() {
    clock->loop();

    int b;
    unsigned long ms;

    b1->loop(&b, &ms);
    if (b == HIGH) {
        if (b1Released && ms > 1000) {
            if (mode > 0) {
                mode = 0;
            } else {
                mode = 1;
                incrementing = false;
            }
            b1Released = false;
        } else if (b1Released && mode > 0 && ms > 20) {
            mode = mode % 2 + 1;
            b1Released = false;
        }
        Serial.print("mode changed to ");
        Serial.println(mode);
    } else if (ms > 20) {
        b1Released = true;
    }

    if (mode != 0) {
        b2->loop(&b, &ms);
        if (b == HIGH) {
            if (!incrementing && ms > 20) {
                incrementing = true;
                incr();
                timer.sync(1000);
            } else if (incrementing) {
                unsigned long dur;
                if (timer.tick(&dur)) {
                    Serial.println("long press repeat");
                    incr();
                    if (dur >= 3000) {
                        if (timer.getInterval() == 1000) {
                            timer.sync(250);
                        } else if (timer.getInterval() == 250) {
                            timer.sync(100);
                        }
                    }
                }
            }
        } else if (incrementing && ms > 20) {
            incrementing = false;
        }
    }

    display->set(encode());
}

void Controller::incr() {
    Serial.print("incr ");
    if (mode == 1) {
        Serial.println("hour");
        clock->incrHour();
    }
    if (mode == 2) {
        Serial.println("minute");
        clock->incrMinute();
    }
}

int Controller::encode() {
    return (clock->h << 6) | clock->m;
}
