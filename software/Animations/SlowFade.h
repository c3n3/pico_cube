#ifndef SLOW
#define SLOW
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
#include "../App/App.h"

class SlowFade: public App
{
public:
    const char* title = "SlowFade";
    void run(uint32_t time = 0, bool timed = false);
};

void SlowFade::run(uint32_t time, bool timed)
{
    uint32_t timer = millis();
    uint32_t timerTotal = millis();
    uint32_t delay = 1000;
    uint8_t power = 15;
    bool goingUp = true;
    while (!timed || millis() - timerTotal < time)
    {
        if (millis() - timer > delay) {
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    for (int k = 0; k < NLSA; k++) {
                        set_led(i, j, k, power);
                    }
                }
            }
            goingUp = !goingUp;
            timer += delay;
            // if (goingUp) {
            //     if (power == 15) {
            //         goingUp = false;
            //     } else {
            //         power = power + 1;
            //     }
            // } else {
            //     if (power == 1) {
            //         goingUp = true;
            //     } else {
            //         power = power - 1;
            //     }
            // }
        }
    }
    clearCube();
}

#endif