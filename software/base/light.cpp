#include "Led.h"

Led::Led(uint8_t led): led(led) {}

Led::operator uint8_t()
{
    return led;
}

Led& Led::operator++(int i)
{
    led++;
    return *this;
}

Led &operator--(int i)
{
    led--;
    return *this;
}

Led& Led::operator=(uint16_t in)
{
    led = in;
    return *this;
}

void setLed(uint16_t in)
{
    led = in;
}

int maxVal()
{
    return 15;
}