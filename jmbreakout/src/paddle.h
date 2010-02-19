#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include "collidingItem.h"
#include "ball.h"

class Paddle : public CollidingItem
{
public:
    Paddle();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    Vector2D collision(Ball const* ball);
    QRectF boundingRect() const;
protected:
    void advance(int phase);
private:
    double speed, width;
};

#endif // PADDLE_H
