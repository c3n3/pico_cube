#pragma once
#include "stdint.h"
typedef unsigned char uint8_t;
typedef uint8_t light_t;
//PINS
#define OUTPUT_CLEAR_actlow 27
#define OUTPUT_ENABLE_actlow 28
#define LAYER_SEL0 0
#define LAYER_SEL1 1
#define LAYER_SEL2 2
#define LAYER_SEL3 3
#define PIN_CS   17
#define SPI_PORT spi0

#define BLANK_PIN 4
#define ENABLE_DEBUG 1

#define LATCH_PIN 21
#define CLOCK_PIN 18
#define DATA_PIN 19
#define NUM_LEDS_SINGLE_AXIS 4
#define BIT_MODULATION_BITS 16

#define NUM_LEDS_LAYER (NUM_LEDS_SINGLE_AXIS * NUM_LEDS_SINGLE_AXIS)
#define NUM_LEDS (NUM_LEDS_SINGLE_AXIS * NUM_LEDS_SINGLE_AXIS * NUM_LEDS_SINGLE_AXIS)
#define NLSA NUM_LEDS_SINGLE_AXIS
#define AXIS_MAX (NLSA - 1)
#define BYTES_PER_LAYER (NUM_LEDS_LAYER / 8)
