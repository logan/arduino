#ifndef BUTTON_H
#define BUTTON_H

class Button {
public:
    Button(int pin);

    void setup();
    void loop(int *state, unsigned long *ms);

private:
    int pin;
    int state;
    unsigned long bounceStart;
};

#endif
