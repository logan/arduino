#include "button.h"
#include "clock.h"
#include "controller.h"
#include "display.h"

static int displayPins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4};

Display display(&displayPins[0]);
Clock clock;
Button b1(2);
Button b2(3);
Controller controller(&b1, &b2, &clock, &display);

void setup() {
    Serial.begin(9600);
    controller.setup();
}

void loop() {
    controller.loop();
}
