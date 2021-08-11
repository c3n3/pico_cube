#include "../App/App.h"
#include "../base/basic_functions.h"
#include "../MathObjects/UltamateTrigLookUp.h"
class Wave: public App
{
private:
    SinLookUpTable<ui8, NLSA * 2> sine;
    CosLookUpTable<ui8, NLSA * 2> cos;
    ui8 iteration;
public:
void run(uint32_t time = 0, bool timed = false)
{
    uint32_t timer = millis();
    uint32_t timerTotal = millis();

    while (!timed || millis() - timerTotal < time)
    {
        char c;
        // TODO: Implement user control
        if (millis() - timer > 100)
        {
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    set_led(i, j, ((sine[i + iteration] / 2) + (sine[j + iteration] / 2)) / 2, 0x00);
                }
            }
            iteration = (iteration + 1) % (NLSA * 2);
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    set_led(i, j, ((sine[i + iteration] / 2) + (sine[j + iteration] / 2)) / 2, 4);
                }
            }
            
            // FIX ALT. Out of bounds iterator
                timer += 100;
        }
    }
    clearCube();
}

};

