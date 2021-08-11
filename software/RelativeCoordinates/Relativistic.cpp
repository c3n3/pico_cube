#include "Relativistic.h"
#include "../base/config.h"
#include <cstdlib>

using namespace Relativistic;


void Relativistic::toStandard(uint8_t& x, uint8_t& y, uint8_t& z, Directions direction) {
    // This is the the flip
    uint8_t temp;
    switch (direction)
    {
        case UP:
            temp = y;
            y = z;
            z = AXIS_MAX - temp;
            break;
        case LEFT:
            temp = x;
            x = AXIS_MAX - z;
            z = temp;
            break;
        case BACKWARD:
            x = AXIS_MAX - x;
            z = AXIS_MAX - z;
            break;
        case RIGHT:
            temp = x;
            x = z;
            z = AXIS_MAX - temp;
            break;
        case DOWN:
            temp = y;
            y = AXIS_MAX - z;
            z = temp;
            break;
        default:
            break;
    }
}


void Relativistic::toRelative(uint8_t& x, uint8_t& y, uint8_t& z, Directions direction) {
    switch (direction)
    { // turns out we can just use the toStandard in reverse to acheive this
        case UP:
            toStandard(x, y, z, DOWN);
            break;
        case LEFT:
            toStandard(x, y, z, RIGHT);
            break;
        case BACKWARD:
            toStandard(x, y, z, BACKWARD);
            break;
        case RIGHT:
            toStandard(x, y, z, LEFT);
            break;
        case DOWN:
            toStandard(x, y, z, UP);
            break;
        default:
            break;
    }
}

uint16_t Relativistic::LED(uint8_t x, uint8_t y, uint8_t z, Directions& direction) {
    toStandard(x, y, z, direction);
    return get_led(x, y, z);
}

void Relativistic::setLED(uint8_t x, uint8_t y, uint8_t z, Directions direction, uint8_t power) {
    toStandard(x, y, z, direction);
    set_led(x, y, z, power);
}

void Relativistic::protectedSetLED(uint8_t x, uint8_t y, uint8_t z, Directions direction, uint8_t power) {
    toStandard(x, y, z, direction);
    set_led(x, y, z, power);
}

//this function switches which orientation you may look at the cube,
// very very useful function, allows writing other helper functions in terms of a direction so that you dont have to have 6 types of the same function for each direction
// the  coordinates go as follows, the face you look at for each direction, the reletive 'z' coordinate is the depth from face, the reletive 'x' is the right and left axis across the face, and the second coordinate is always the reletive 'y'
void Relativistic::setDirectionalLED(const uint8_t firstCord, const uint8_t secondCord, const uint8_t thirdCord, Directions direction, uint8_t power)
{
    switch (direction)
    { //you can set leds
    case UP:
        set_led(firstCord, secondCord, thirdCord, power);
        break;
    case FORWARD:
        set_led(firstCord, thirdCord, secondCord, power);
        break;
    case LEFT:
        set_led(AXIS_MAX - thirdCord, secondCord, firstCord, power);
        break;
    case BACKWARD:
        set_led(firstCord, AXIS_MAX - thirdCord, secondCord, power);
        break;
    case RIGHT:
        set_led(thirdCord, secondCord, AXIS_MAX - firstCord, power);
        break;
    case DOWN:
        set_led(AXIS_MAX - firstCord, secondCord, AXIS_MAX - thirdCord, power);
        break;
    default:
        break;
    }
}
uint8_t Relativistic::getDirectionalLED(const uint8_t firstCord, const uint8_t secondCord, const uint8_t thirdCord, Directions direction) {
        switch (direction)
        { //or you can call the array for the cube, it returns the value
        case UP:
            return get_led(firstCord, secondCord, thirdCord);
            break;
        case FORWARD:
            return get_led(firstCord, thirdCord, secondCord);
            break;
        case LEFT:
            return get_led(AXIS_MAX - thirdCord, secondCord, firstCord);
            break;
        case BACKWARD:
            return get_led(firstCord, AXIS_MAX - thirdCord, secondCord);
            break;
        case RIGHT:
            return get_led(thirdCord, secondCord, AXIS_MAX - firstCord);
            break;
        case DOWN:
            return get_led(AXIS_MAX - firstCord, secondCord, AXIS_MAX - thirdCord);
            break;

        default:
            break;
        }
    return 0; // if people input nonsense, give them arbitrary nonsense
}


//TODO: delete this thing if safe
void Relativistic::setRandomLED(uint8_t leds, Relativistic::Directions direction, uint8_t power, bool threeD)
{
    if (!threeD)
    {
        for (uint8_t i = 0; i < leds; i++)
        {
            Relativistic::setDirectionalLED(rand() % NLSA, rand() % NLSA, 0, direction, power);
        }
    }
}

//no up or down yet
void Relativistic::angledMove(uint8_t rise, uint8_t run, Relativistic::Directions direction, uint8_t power)
{
    // Make this?
}

/***************************************************************************
 *
 *  ATTENTION: This is horribly disgusting, whomever wrote this should report for incineration. 
 * 
 * 
 *   Move Row function
 *   firstCoord and secondCoord determine which row will be shifted in accordance with the specified viewPoint
 *   viewPoint determines which plane will be looked at for the two coordinates to shift there row
 *   specificColor tells it which color it should shift in the cube default is 1, this will shift all colors
 *   collective determines whether this function is allowed to 'push' a lit LED off the cube or not
 *   start is at which index the function will start shifting, Default 0 for the beginning of any row
 *   end is the index the function will stop
 *   color will change the color of any shifted led, Default 1 will not change the color of shifted leds
 *
 ***************************************************************************/

void Relativistic::moveRow(uint8_t firstCoord, uint8_t secondCoord, Directions viewPoint, uint16_t specificColor, bool collective, uint8_t start, uint8_t end, uint8_t power)
{
    if (!collective && end == AXIS_MAX)
    {
        Relativistic::setDirectionalLED(firstCoord, secondCoord, AXIS_MAX, viewPoint);
    }
    for (int i = (AXIS_MAX - 1) - (AXIS_MAX - end); i >= 0 + start; i--)
    {
        if (specificColor == 1)
        {
            if (getDirectionalLED(firstCoord, secondCoord, i, viewPoint) != 0)
            {
                if (collective)
                {
                    if (getDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint) == 0)
                    {
                        if (power == 1)
                        {
                            Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, getDirectionalLED(firstCoord, secondCoord, i, viewPoint));
                        }
                        else
                        {
                            Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint, power);
                        }
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint, 0);
                    }
                }
                else
                {

                    if (power == 1)
                    {
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, getDirectionalLED(firstCoord, secondCoord, i, viewPoint));
                    }
                    else
                    {
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, power);
                    }
                    Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint);
                }
            }
        }
        else
        {
            if (getDirectionalLED(firstCoord, secondCoord, i, viewPoint) != 0 && getDirectionalLED(firstCoord, secondCoord, i, viewPoint) == specificColor)
            {
                if (collective)
                {
                    if (getDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint) != specificColor)
                    {
                        if (power == 1)
                        {
                            Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, getDirectionalLED(firstCoord, secondCoord, i, viewPoint)); 
                        }
                        else
                        {
                            Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint, power);
                        }
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint);
                    }
                }
                else
                {

                    if (power == 1)
                    {
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, getDirectionalLED(firstCoord, secondCoord, i, viewPoint));
                    }
                    else
                    {
                        Relativistic::setDirectionalLED(firstCoord, secondCoord, i + 1, viewPoint, power);
                    }
                    Relativistic::setDirectionalLED(firstCoord, secondCoord, i, viewPoint);
                }
            }
        }
    }
}
