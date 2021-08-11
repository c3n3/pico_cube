#ifndef SWIRL
#define SWIRL
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
#include "../Input/Input.h"
#include "../App/App.h"
class Swirl: public App
{
public:
    const String title = "Swril";
    void run(uint32_t time = 0, bool timed = false);
};

void Swirl::run(uint32_t time, bool timed)
{
    bool start = false;
    clearCube();
    uint32_t swirlTimer = millis();
    uint32_t timer = millis();

    while (!timed || millis() - timer < time)
    {
        char c;
        // TODO: Implement user control
        if (!start)
        {
            for (int i = 0; i < 12; i++)
            {
                Relativistic::setLED(i, i, AXIS_MAX, Relativistic::FORWARD, 0xFF);
                Relativistic::setLED(i, i, AXIS_MAX, Relativistic::BACKWARD, 0xFF);
                Relativistic::setLED(i, i, AXIS_MAX, Relativistic::LEFT, 0xFF);
                Relativistic::setLED(i, i, AXIS_MAX, Relativistic::RIGHT, 0xFF);
            }
            for (int i = 1; i < AXIS_MAX; i++)
            {
                Relativistic::setLED(i, AXIS_MAX - i, (AXIS_MAX - 1), Relativistic::FORWARD, 0xFF);
                Relativistic::setLED(i, AXIS_MAX - i, (AXIS_MAX - 1), Relativistic::BACKWARD, 0xFF);
                Relativistic::setLED(i, AXIS_MAX - i, (AXIS_MAX - 1), Relativistic::LEFT, 0xFF);
                Relativistic::setLED(i, AXIS_MAX - i, (AXIS_MAX - 1), Relativistic::RIGHT, 0xFF);
            }
            start = true;
        }
        if (millis() - swirlTimer > 100)
        {
            for (int k = 0; k < 12; k++)
            {
                Relativistic::moveRow(AXIS_MAX, k, Relativistic::FORWARD);
                Relativistic::moveRow(AXIS_MAX, k, Relativistic::BACKWARD);
                Relativistic::moveRow(AXIS_MAX, k, Relativistic::LEFT);
                Relativistic::moveRow(AXIS_MAX, k, Relativistic::RIGHT);
            }
            for (int i = 0; i < 4; i++)
            {
                for (int k = 1; k < AXIS_MAX; k++)
                {
                    Relativistic::moveRow(1, k, Relativistic::Directions(i + 1), 1, false, 1, (AXIS_MAX - 1));
                }
            }

            swirlTimer = millis();
        }
    }
    clearCube();
}

#endif