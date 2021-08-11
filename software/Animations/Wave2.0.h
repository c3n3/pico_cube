#include "../App/App.h"
#include "../base/basic_functions.h"
#include "../MathObjects/UltamateTrigLookUp.h"
class Wave2p0: public App
{
private:
    SinLookUpTable<uint8_t, NLSA * 2> sine;
    CosLookUpTable<uint8_t, NLSA * 2> cos;
    uint8_t iteration;
public:
void run(uint32_t time = 0, bool timed = false)
{
    int wave = rand() % 7;
    uint32_t timer = millis();
    uint32_t timerTotal = millis();
    auto func = [this, wave](int i, int j, int k, int iter, int p) -> void {
        if (wave == 0) lim_set_led(((this->sine[k + iter] / 2) + (this->sine[j + iter] / 2)) / 2, ((this->cos[i + iter] / 2) + (this->cos[k + iter] / 2)) / 2, k, p);
        else if (wave == 1) lim_set_led(i, j, ((this->sine[j + iter] / 2) + (this->cos[i + iter] / 2)) / 2, p);
        else if (wave == 2) lim_set_led(i, (this->sine[i + iter] / 2), (this->cos[i + iter] / 2), p);
        else if (wave == 3) lim_set_led(i, j, ((this->sine[i + iter] / 2) + (this->sine[j + iter] / 2)) / 2, p);
        else if (wave == 4) lim_set_led(((this->sine[k + iter] / 2) + (this->sine[j + iter] / 2)) / 2, ((this->sine[i + iter] / 2) + (this->sine[k + iter] / 2)) / 2, k, p);
        else if (wave == 5) lim_set_led(i, ((this->sine[i + iter] / 2)), ((this->sine[i + iter] / 2) + (this->sine[j + iter] / 2)) / 2, p);
        else if (wave == 6) lim_set_led((this->sine[iter] / 2), (this->sine[iter + k] / 2), (this->sine[i + iter] / 2), p);
    };
    while (!timed || millis() - timerTotal < time)
    {
        char c;
        // TODO: Implement user control
        if (millis() - timer > 100)
        {
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    for (int k = 0; k < NLSA; k++) {
                        func(i, j, k, iteration, 0);
                    }
                }
            }
            iteration = (iteration + 1) % (NLSA * 2);
            for (int i = 0; i < NLSA; i++) {
                for (int j = 0; j < NLSA; j++) {
                    for (int k = 0; k < NLSA; k++) {
                        func(i, j, k, iteration, 4);
                    }
                }
            }
            
            // FIX ALT. Out of bounds iterator
                timer += 100;
        }
    }
    clearCube();
}

};

