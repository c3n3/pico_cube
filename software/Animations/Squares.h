#ifndef PARTICLE_TEST
#define PARTICLE_TEST
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../RelativeCoordinates/Relativistic.h"
#include "../Input/Input.h"
#include "../App/App.h"
#include "../ParticleSystem/Particle.h"

class Squares: public App
{
public:
    const String title = "Snow";
    void run(uint32_t time = 0, bool timed = false);
};

static void drawCube(Vector<uint8_t> pos, uint8_t length, uint8_t power)
{
    for (int i = pos.x; i < pos.x + length; i++) {
        for (int j = pos.y; j < pos.y + length; j++) {
            for (int k = pos.z; k < pos.z + length; k++) {
                set_led(i,j,k,power);
            }
        }
    }
}

void Squares::run(uint32_t time, bool timed)
{
    uint32_t timer = millis();
    uint32_t timerP = millis();
    uint32_t timerTotal = millis();
    bool onX = true;
    bool xUP = true;
    bool yUP = true;
    light_t power = 1;
    bool pUp = true;
    auto cube = Vector<uint8_t>(0,0,0);
    auto cube2 = Vector<uint8_t>(0,0,4);
    while (!timed || millis() - timerTotal < time)
    {
        if (millis() - timerP > 50) {
            if (pUp) {
                power = power + 1;
                if (power == 15) {
                    pUp = false;
                }
            } else {
                power = power - 1;
                if (power == 1) {
                    pUp = true;
                }
            }
            drawCube(cube, 4, power);
            drawCube(cube2, 4, power);
            timerP += 50;
        }
        if (millis() - timer > 50) {
            drawCube(cube2, 4, 0);
            drawCube(cube, 4, 0);
            uint8_t* edit = onX ? &cube.x : &cube.y;
            uint8_t* edit2 = onX ? &cube2.y : &cube2.x;
            bool* onUp = onX ? &xUP : &yUP;
            if (*onUp) {
                *edit = *edit + 1;
                *edit2 = *edit2 + 1;
                if (*edit == AXIS_MAX - 3) {
                    onX = !onX;
                    *onUp = !*onUp;
                } 
            } else {
                *edit2 = *edit2 - 1;
                *edit = *edit - 1;
                if (*edit == 0) {
                    onX = !onX;
                    *onUp = !*onUp;
                } 
            }
            drawCube(cube, 4, power);
            drawCube(cube2, 4, power);
            timer += 50;
        }
    }
    clearCube();
}

#endif