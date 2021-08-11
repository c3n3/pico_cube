#pragma once
#include "../App/App.h"
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
class Space : public App
{
private:
    Relativistic::Directions current;

    uint32_t interval;

    const uint16_t intervalAcceleration = 200; // the interval in which we set a new interval
    const uint8_t intervalJump = 100;           // in milliseconds the max the interval can jump
    const uint16_t intervalMax = 1000;         // the max the interval
    const uint16_t intervalMin = 100;          // the minimum the interval can go
    const uint16_t peakSustain = 1000;         // how long the program stops at the max interval
    const uint8_t ledDensity = 1;

    bool speedUp;
    bool sustain;
    bool init() {
        return CONTINUE_PROGRAM;
    }
    void moveAll()
    {
        for (int x = 0; x < NLSA; x++)
        {
            for (int y = 0; y < NLSA; y++)
            {
                Relativistic::moveRow(x, y, Relativistic::UP, 1); // move all colors
            }
        }
    };

    void randomLEDs()
    {
        if (rand() % 25 != 1) {
            Relativistic::setRandomLED(ledDensity, Relativistic::UP, rand() % 4);
        } else {
            Relativistic::setRandomLED(ledDensity, Relativistic::UP, rand() % 0xFF);
        }
    };

    void getNextInterval()
    {
        speedUp ? (interval - (millis() % intervalJump)) : (interval + (millis() % intervalJump));
    };

    Relativistic::Directions getNextDirection()
    {
        return Relativistic::Directions(millis() % 6); // just using millis for random for now
    };

protected:
    bool frame()
    {
        if (millis() - timer > 100)
        {
            moveAll();
            randomLEDs();
            timer += 100;
        } 
        return CONTINUE_PROGRAM; // this thing always continues
    };

public:
    Space()
    {
        speedUp = true;
        sustain = false; // when will sustain be implimented
        interval = 750; // 750 miliseconds to start the function
        current = Relativistic::Directions(millis() % 6);
    };
};