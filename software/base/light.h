#pragma once
#include "config.h"

/**
 * Represents an LED
 */
struct Led
{
public:
    uint8_t led;
    
    Led(uint8_t power);

    operator uint8_t();

    Led &operator++(int);

    Led &operator--(int);

    Led &operator=(uint8_t in);

    void setLed(uint8_t in);

    int maxVal();
};