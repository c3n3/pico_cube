#include "HelpfulFunctions.h"
#include "config.h"

uint8_t Help::normalize(float& notNormal)
{
    uint8_t normalized = (notNormal + 0.5);
    if (normalized - 1 > (AXIS_MAX - 1))
    {
        normalized = normalized > 200 ? 0 : AXIS_MAX; // that 200 is completely arbitrary, but it should work
    }
    return normalized;
}

// delete all of a color on the entire cube
void Help::eradicate(light_t power)
{
    for (uint8_t i = 0; i < 12; i++)
    {
        for (uint8_t j = 0; j < 12; j++)
        {
            for (uint8_t k = 0; k < 12; k++)
            {
                if (get_led(i, j, k) == power)
                {
                    set_led(i, j, k, 0);
                }
            }
        }
    }
}

// draws a box based on the 6 coordinates (Two Points in the cube) and the color (This thing definitley needs rewritting)
void Help::DrawFigure(int x1, int y1, int z1, int x2, int y2, int z2, light_t power)
{
    // make this?
}