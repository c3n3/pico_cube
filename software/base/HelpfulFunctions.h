#ifndef HELPFUL_FUNCTIONS
#define HELPFUL_FUNCTIONS
#include "basic_functions.h"
/**
 * @brief this contains functions that can be very useful for making animation, but dont quite make the bare metal Basic_Functions.h standard
 * In other words, these implementations are agnostic to the Cube currently running
 */
class Help
{
public:
    // delete all of a color on the entire cube
    static void eradicate(light_t power);

    // used to make float values into integers
    static uint8_t normalize(float& notNormal);

    // draws a box based on the 6 coordinates (Two Points in the cube) and the color (This thing definitley needs rewritting)
    static void DrawFigure(int x1, int y1, int z1, int x2, int y2, int z2, light_t power);
};
#endif