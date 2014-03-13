#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    Display(int *pins);

    void setup();
    void set(int encoded);

private:
    int *pins;
};

#endif
