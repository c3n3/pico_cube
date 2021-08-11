#pragma once
#include "../base/HelpfulFunctions.h"
namespace Relativistic
{
    // direction of the thing
    enum Directions {UP, FORWARD, LEFT, BACKWARD, RIGHT, DOWN};

    // returns color of the specified LED
    uint16_t LED(uint8_t x, uint8_t y, uint8_t z, Directions& direction);
    
    // set a relative LED coordinate to a color
    void setLED(uint8_t x, uint8_t y, uint8_t z, Directions direction, uint8_t power);
    
    // set a relative LED coordinate to a color, but also make sure it is protected
    void protectedSetLED(uint8_t x, uint8_t y, uint8_t z, Directions direction, uint8_t color);

    // This is a very, very useful function that creates relativistic coordinates that revolve around the viewing angle of direction parameter; This should be broken to two functions however
    void setDirectionalLED(const uint8_t firstCord, const uint8_t secondCord, const uint8_t thirdCord, Relativistic::Directions direction, uint8_t power = 0);
    
    uint8_t getDirectionalLED(const uint8_t firstCord, const uint8_t secondCord, const uint8_t thirdCord, Directions direction);
    
    // Go from a standard coordinate to a relative coordinate
    void toRelative(uint8_t& x, uint8_t& y, uint8_t& z, Directions direction);

    // go from a relative coordinate to a standard one, 
    void toStandard(uint8_t& x, uint8_t& y, uint8_t& z, Directions direction);

    //TODO: delete this thing if safe
    void setRandomLED(uint8_t leds, Relativistic::Directions direction, uint8_t power, bool threeD = false);

    //no up or down yet
    void angledMove(uint8_t rise, uint8_t run, Relativistic::Directions direction, uint8_t power);

    // this is a very badly written useful function, check out the definition for a better description
    void moveRow(uint8_t firstCoord, uint8_t secondCoord, Relativistic::Directions viewPoint, uint16_t specificColor = 1, bool collective = false, uint8_t start = 0, uint8_t end = AXIS_MAX, uint8_t power = 1);

};