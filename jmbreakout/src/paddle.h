#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <typeinfo>

#include "collidingItem.h"
#include "ball.h"
#include "breakout.h"

class Paddle : public CollidingItem
{
public:
    Paddle(Breakout* b);
    enum paddleSize { TINY = 20, NORMAL = 60, LARGE = 120 };
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    Vector2D collision(Ball const* ball);
    QRectF boundingRect() const;
protected:
    void advance(int phase);
private:
    double speed;
    paddleSize width;
    int bonusWidth;
    int timer;
    Breakout* parent;
    void handleCollision();
};

#endif // PADDLE_H
