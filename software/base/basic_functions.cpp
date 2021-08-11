#include "basic_functions.h"
#include "config.h"
#include "pico/time.h"
#include <cstdlib>
#include <cstring>

extern uint8_t leds0[NUM_LEDS / 8]; // each set of brightness
extern uint8_t leds1[NUM_LEDS / 8]; // each set of brightness
extern uint8_t leds2[NUM_LEDS / 8]; // each set of brightness
extern uint8_t leds3[NUM_LEDS / 8]; // each set of brightness

uint32_t millis() {
    return to_ms_since_boot(get_absolute_time());
}

void bitWrite(uint8_t& t, int bit, int val) {
    if (val == 0) {
        t = t & ~(0x80 >> bit);
    } else {
        t = t | (0x80 >> bit);
    }
}


void lim_set_led(uint8_t x, uint8_t y, uint8_t z, uint8_t power) {
    if (power > 200) power = 0;
    if (power > 15) power = 15;
    if (x > 100) x = 0;
    if (y > 100) y = 0;
    if (z > 100) z = 0;
    if (x > AXIS_MAX) x = AXIS_MAX;
    if (y > AXIS_MAX) y = AXIS_MAX;
    if (z > AXIS_MAX) z = AXIS_MAX;
    set_led(x,y,z,power);
}
void set_led(uint8_t x, uint8_t y, uint8_t z, uint8_t power) {
    if (x > AXIS_MAX || y > AXIS_MAX || z > AXIS_MAX) return;
    // y = 7 - y; // just makes the thing
    int byte = int((z*NUM_LEDS_LAYER+y*NUM_LEDS_SINGLE_AXIS + x)/8);
    int ledNum = (z*NUM_LEDS_LAYER)+(y*NUM_LEDS_SINGLE_AXIS) + x - (8 * byte);
    bitWrite(leds3[byte], ledNum, (power & 0x08) >> 3); //  
    bitWrite(leds2[byte], ledNum, (power & 0x04) >> 2); //  
    bitWrite(leds1[byte], ledNum, (power & 0x02) >> 1); //  
    bitWrite(leds0[byte], ledNum, (power & 0x01) >> 0); //  
}

void set_led_rgb(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b) {
    
}

uint8_t get_led(uint8_t x, uint8_t y, uint8_t z) {
    // y = 7 - y; // just makes the thing
    int byte = int((z*NUM_LEDS_LAYER+y*NUM_LEDS_SINGLE_AXIS + x)/8);
    int ledNum = (z*NUM_LEDS_LAYER)+(y*NUM_LEDS_SINGLE_AXIS) + x - (8 * byte);
    uint8_t ret = 0;
    ret |= ((leds3[byte] >> ledNum) & 0x01) << 3;  
    ret |= ((leds2[byte] >> ledNum) & 0x01) << 2;  
    ret |= ((leds1[byte] >> ledNum) & 0x01) << 1;  
    ret |= ((leds0[byte] >> ledNum) & 0x01) << 1;
    return ret;
}


//self explainatory
void clearCube(){
    memset((uint8_t *)leds0, 0x00, NUM_LEDS / 8);
    memset((uint8_t *)leds1, 0x00, NUM_LEDS / 8);
    memset((uint8_t *)leds2, 0x00, NUM_LEDS / 8);
    memset((uint8_t *)leds3, 0x00, NUM_LEDS / 8);
}
