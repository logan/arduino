#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer(unsigned long interval);

    void sync(unsigned long interval);
    bool tick(unsigned long *duration=NULL);

    unsigned long getInterval() { return interval; }

private:
    unsigned long base;
    unsigned long interval;
    int baseModulus;
    int curModulus;
};

#endif
