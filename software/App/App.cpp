#include "App.h"
#include "../base/basic_functions.h"
#include "pico/time.h"

bool App::init() {return CONTINUE_PROGRAM;}
void App::end() {}

bool App::characterInput()
{
    // Implement user input.
    return true;
}

bool App::frame()
{
    return STOP_PROGRAM; // this kills the program
};

// virtual bool runEndCondition();

void App::run(uint32_t time, bool timed)
{
    uint32_t appTimer = millis();
    timer = millis();
    if (init() == STOP_PROGRAM) {  // init the function
        return;
    }
    // This may look confusing, but the magic is in the characterInput() and frame() function calls
    // this loop will continueously check the conditions until one is false
    // The way this loop ends is either the characterInput() function takes in an ESC character, or YOUR frame program returns STOP_PROGRAM
    while ((!timed || millis() - appTimer < time) && characterInput() && frame());
    clearCube();
    end();
};