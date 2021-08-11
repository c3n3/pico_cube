#ifndef SNOW
#define SNOW
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
#include "../Input/Input.h"
#include "../App/App.h"

class Snow: public App
{
public:
    const String title = "Snow";
    void run(uint32_t time = 0, bool timed = false);
};

void Snow::run(uint32_t time, bool timed)
{
    uint32_t timer = millis();
    uint32_t timerTotal = millis();

    while (!timed || millis() - timerTotal < time)
    {
        char c;
        // TODO: Implement user control
        if (millis() - timer > 260)
        {
            int count = 0;
            for (int i = 0; i < NLSA; i++)
            {
                for (int f = 0; f < NLSA; f++)
                {
                    count = 0;
                    for (int g = 0; g < 3; g++)
                    {
                        if (get_led(i, f, g) != 0)
                        {
                            count += 1;
                        }
                        if (count == 3)
                        {
                            set_led(i, f, g, 0);
                        }
                    }
                }
            }

            for (int i = 0; i < NLSA; i++)
            {
                for (int j = 0; j < NLSA; j++)
                {
                    if (rand() % 25 != 1)
                    {
                        Relativistic::moveRow(j, i, Relativistic::DOWN, 1, true);
                    }
                    else
                    {
                        Relativistic::moveRow(j, i, Relativistic::DOWN, 1, false);
                    }
                }
            }
            int num = rand() % NLSA;
            int num1 = rand() % NLSA;
            int num2 = rand() % NLSA;
            set_led(num, num2, AXIS_MAX, 4);
            set_led(num1, num, AXIS_MAX, 4);
            set_led(num2, num1, AXIS_MAX, 4);
            timer += 260;
        }
    }
    clearCube();
}

#endif