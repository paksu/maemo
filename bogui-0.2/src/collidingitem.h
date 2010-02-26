#ifndef COLLIDINGITEM_H
#define COLLIDINGITEM_H

#include <QGraphicsRectItem>

#include "vector2d.h"

class Ball;
class Bonus;
class Breakout;

class CollidingItem : public QGraphicsRectItem
{
public:
    CollidingItem();
    virtual Vector2D collision(Ball const* ball);
    Breakout* breakout();
};

#include "ball.h"
#include "bonus.h"

#endif // COLLIDINGITEM_H
