#ifndef COLLIDING_H
#define COLLIDING_H

#include "ball.h"

class Collidable
{
public:
    virtual void collision(Ball* ball) = 0;
};

#endif // COLLIDING_H
