#ifndef COLLIDING_H
#define COLLIDING_H

#include <QGraphicsRectItem>

#include "vector2d.h"

class Ball;

class CollidingItem : public QGraphicsRectItem
{
public:
    CollidingItem();
    // returns extra impact to add for the ball
    virtual Vector2D collision(Ball const* ball);
};

#include "ball.h"

#endif // COLLIDING_H
