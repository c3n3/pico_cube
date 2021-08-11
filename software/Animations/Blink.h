#ifndef BLINK
#define BLINK
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
#include "../App/App.h"

class Blink: public App
{
public:
    const char* title = "Blink";
    void run(uint32_t time = 0, bool timed = false);
};

void Blink::run(uint32_t time, bool timed)
{
    uint32_t timer = millis();
    uint32_t timerTotal = millis();
    uint32_t delay = 100;
    bool on = false;
    while (!timed || millis() - timerTotal < time)
    {
        if (millis() - timer > delay) {
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    for (int k = 0; k < NLSA; k++) {
                        set_led(i, j, k, on ? 0xFF : 0);
                    }
                }
            }
            on = !on;
            timer += delay;
            delay = delay > 4 ? delay - 3 : 100;
        }
    }
    clearCube();
}

#endif