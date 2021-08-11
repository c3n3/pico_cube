#pragma once
#include "../base/basic_functions.h"
#include "../base/HelpfulFunctions.h"
#include "../MathObjects/Vector.h"
#include "Arduino.h"
#include "./../types/typedef.h"

/**
 * @brief This is a particle that has position, acceleration, velocity, and color; Also contains various 'effects' (what happens when the particle hits a wall)
 * 
 */
class Particle
{
private:
    uint8_t power;
    void thatOnePhysicsEquation();
    void handleWallHit(float&,float&,float&,uint32_t&,float&);
public:
    const float resolution; // (milliseconds per update) for the particle's 'physics' engine
    uint32_t timeStartX;
    uint32_t timeStartY;
    uint32_t timeStartZ;
    uint32_t timer; // timer for use when 
    // this is useful so you can reasign a particle
    Particle& operator = (const Particle&);

    float tolerance;

    // the current point of the particle
    Vector<float> point;
    
    // the origin of the point
    Vector<float> origin;

    // the initialSpeed in LEDs per second
    Vector<float> velocity; 
    
    // LEDs per second per second
    Vector<float> acceleration;
    
    // A useful enum for defining what happens when the particle reaches a wall
    enum WallEffects {
        STICK,
        BOUNCE,
        PASS_THROUGH,
        SLIDE,
        TELEPORT,
    };

    // determines what happens when a particle hits a wall
    WallEffects effect;

    // when working with particles, call this function as much as possible so that the particles can update their position
    void updatePosition(); 

    /**
     * @brief Construct a new Particle object
     * 
     * @param point the start point of the object
     * @param velocity the starting velocity of the particle
     * @param acceleration the acceleration of the particle
     * @param resolution the 'resolution' of the particle meaning how often the particle gets its position updated
     * @param effect the WallEffect that determines what happens when the particle hits a wall
     * @param color the color of the particle 
     */
    Particle(Vector<float> point, Vector<float> velocity, Vector<float> acceleration, uint16_t resolution, WallEffects effect, uint8_t power = 0xFF, float tolerance = 0.49);

    Particle();

    // this draws the particle with a given color
    void drawSelf(const uint8_t power);

    // this draws the particle with the internal color
    void drawSelf();
};