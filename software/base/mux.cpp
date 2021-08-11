#include "mux.h"
#include "config.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

uint8_t leds0[NUM_LEDS / 8]; // each set of brightness
uint8_t leds1[NUM_LEDS / 8]; // each set of brightness
uint8_t leds2[NUM_LEDS / 8]; // each set of brightness
uint8_t leds3[NUM_LEDS / 8]; // each set of brightness

/*
    while (true) {
        spi_write_blocking(SPI_PORT, &t, 1);
        gpio_put(LATCH_PIN, 0);
        sleep_ms(10);
        gpio_put(LATCH_PIN, 1);
        sleep_ms(100);
        gpio_put(LAYER_SEL0, 0);
        gpio_put(LAYER_SEL3, 1);
        sleep_ms(100);
        gpio_put(LAYER_SEL3, 0);
        gpio_put(LAYER_SEL0, 1);
    }


*/

void run_mux(void) {
    while (true) {
        sleep_us(100);
        static uint8_t layer = 0;
        static uint8_t it = 1;
        gpio_put(OUTPUT_ENABLE_actlow, 1);//The first thing we do is turn all of the LEDs OFF, by writing a 1 to the blank pin
        if (layer == 0) {
            gpio_put(LAYER_SEL3, 0);
            gpio_put(LAYER_SEL0, 1);
        } else if (layer == 1) {
            gpio_put(LAYER_SEL0, 0);
            gpio_put(LAYER_SEL1, 1); 
        } else if (layer == 2) {
            gpio_put(LAYER_SEL1, 0);
            gpio_put(LAYER_SEL2, 1);
        } else if (layer == 3) {
            gpio_put(LAYER_SEL2, 0);
            gpio_put(LAYER_SEL3, 1);
        }

        if (it > 7) { // 8, 9, 10, 11, 12, 13, 14, 15
            for (int i = layer * BYTES_PER_LAYER; i < layer * BYTES_PER_LAYER + BYTES_PER_LAYER; i++) {
                spi_write_blocking(SPI_PORT, leds3 + i, 1);
            }
        }
        else if (it > 3) { // 4, 5, 6, 7
            for (int i = layer * BYTES_PER_LAYER; i < layer * BYTES_PER_LAYER + BYTES_PER_LAYER; i++) {
                spi_write_blocking(SPI_PORT, leds2 + i, 1);
            }
        }
        else if (it > 1) { // 2, 3
            for (int i = layer * BYTES_PER_LAYER; i < layer * BYTES_PER_LAYER + BYTES_PER_LAYER; i++) {
                spi_write_blocking(SPI_PORT, leds1 + i, 1);
            }
        }
        else { // 1
            for (int i = layer * BYTES_PER_LAYER; i < layer * BYTES_PER_LAYER + BYTES_PER_LAYER; i++) {
                spi_write_blocking(SPI_PORT, leds0 + i, 1);
            }
        }

        it++;
        layer++;
        if (it == BIT_MODULATION_BITS) {
            it = 1;
        }

        if (layer == NUM_LEDS_SINGLE_AXIS) {
            layer = 0;
        }

        gpio_put(LATCH_PIN, 1);//Latch pin HIGH
        gpio_put(LATCH_PIN, 0);//Latch pin LOW
        gpio_put(OUTPUT_ENABLE_actlow, 0);//blank pin LOW
    }
}

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void mux_init() 
{
   stdio_init_all();
    for (int i = 0; i < NUM_LEDS / 8; i++) {
        leds0[i] = 0;
        leds1[i] = 0;
        leds2[i] = 0;
        leds3[i] = 0;
    }
    // SPI initialisation. This example will use SPI at 1MHz.
    spi_init(SPI_PORT, 1000*1000);

    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(CLOCK_PIN,  GPIO_FUNC_SPI);
    gpio_set_function(DATA_PIN, GPIO_FUNC_SPI);
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_init(LATCH_PIN);
    gpio_init(OUTPUT_CLEAR_actlow);
    gpio_init(OUTPUT_ENABLE_actlow);
    gpio_init(LAYER_SEL0);
    gpio_init(LAYER_SEL1);
    gpio_init(LAYER_SEL2);
    gpio_init(LAYER_SEL3);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(OUTPUT_CLEAR_actlow, GPIO_OUT);
    gpio_set_dir(OUTPUT_ENABLE_actlow, GPIO_OUT);
    gpio_set_dir(LATCH_PIN, GPIO_OUT);
    gpio_set_dir(LAYER_SEL0, GPIO_OUT);
    gpio_set_dir(LAYER_SEL1, GPIO_OUT);
    gpio_set_dir(LAYER_SEL2, GPIO_OUT);
    gpio_set_dir(LAYER_SEL3, GPIO_OUT);

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    gpio_put(LAYER_SEL0, 0);
    gpio_put(LAYER_SEL1, 0);
    gpio_put(LAYER_SEL2, 0);
    gpio_put(LAYER_SEL3, 0);
    gpio_put(LED_PIN, 1);
    gpio_put(OUTPUT_CLEAR_actlow, 1);
    gpio_put(OUTPUT_ENABLE_actlow, 0);
}