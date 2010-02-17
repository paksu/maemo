#ifndef COLLIDING_H
#define COLLIDING_H

#include "ball.h"
#include "vector2d.h"

class Colliding
{
public:
    // returns extra impact to add for the ball
    virtual Vector2D collision(Ball const* ball) = 0;
};

#endif // COLLIDING_H
