#pragma once
#include "config.h"
#include "light.h"
#include <cstdlib>

void set_led(uint8_t x, uint8_t y, uint8_t z, light_t brightness);
void lim_set_led(uint8_t x, uint8_t y, uint8_t z, light_t brightness);
uint8_t get_led(uint8_t x, uint8_t y, uint8_t z);
void clearCube();
uint32_t millis();

#define TRIPLE_LOOP(x,y,z) for(light_t x = 0;x < NUM_LEDS_SINGLE_AXIS;x++){\
                                for(light_t y = 0;y < NUM_LEDS_SINGLE_AXIS;y++){\
                                    for(light_t z = 0;z < NUM_LEDS_SINGLE_AXIS;z++){
#define END_TRIPLE_LOOP }}}
#define MILLIS_TIMER(x, timer) if (millis() - (timer) > (x)) {timer += (x);
#define END_MILLIS_TIMER } 
