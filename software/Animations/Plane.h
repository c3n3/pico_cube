#include "../App/App.h"
#include "../base/basic_functions.h"
#include "../MathObjects/UltamateTrigLookUp.h"
class Plane: public App
{
private:
    SinLookUpTable<ui8, NLSA * 2> sine;
    CosLookUpTable<ui8, NLSA * 2> cos;
    ui8 iteration;
public:
void run(uint32_t time = 0, bool timed = false)
{
    uint32_t timer = millis();
    uint32_t timer2 = millis();
    uint32_t timerTotal = millis();

    while (!timed || millis() - timerTotal < time)
    {
        char c;
        // TODO: Implement user control
        if (millis() - timer > 250)
        {
            for (int i = 0; i < NLSA; i++) {
                for (int k = 0; k < NLSA; k++) {
                    for (int j = 0; j < NLSA; j++) {
                        lim_set_led(i,j,k,0);
                    }
                }
            }
            iteration = (iteration + 1) % (NLSA * 2);
            if (millis() - timer2 > 5000) {
                for (int i = 0; i < NLSA; i++) {
                    for (int k = 0; k < NLSA; k++) {
                        for (int j = 0; j < NLSA; j++) {
                            lim_set_led(i,j,k,15);
                        }
                    }
                }
                timer2 += 5000;
            }
            
            // FIX ALT. Out of bounds iterator
                timer += 250;
        }
    }
    clearCube();
}

};

