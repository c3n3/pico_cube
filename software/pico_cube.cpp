#include <stdio.h>
#include "base/mux.h"
#include "base/basic_functions.h"
#include <cstdlib>
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "pico/multicore.h"
// #include "pico/"
#include "Animations/Wave2.0.h"
#include "Animations/Blink.h"
#include "Animations/SlowFade.h"

int main()
{
    mux_init();
    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);

    multicore_launch_core1(run_mux);
    int j;
    srand(j + millis() + (uint32_t)&j + adc_read());
    Wave2p0 space;
    // for (int i = 0; i < NLSA; i++) {
    // for (int j = 0; j < NLSA; j++) {
    // for (int k = 0; k < NLSA; k++) {
    //     set_led(i,j,k, 1);
    // }
    // }
    // }
    while (true) {
        space.run();
    }
    return 0;
}
