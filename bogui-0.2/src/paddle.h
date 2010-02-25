#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <typeinfo>

#include "collidingitem.h"
#include "ball.h"

class Breakout;

class Paddle : public CollidingItem
{
public:
    Paddle(Breakout* b);
    enum paddleSize { TINY = 20, NORMAL = 60, LARGE = 120 };
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    Vector2D collision(Ball const* ball);
    QRectF boundingRect() const;
    void setBonusWidth(int bonusWidth);
    void setTimer(int timer);
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

#include "breakout.h"

#endif // PADDLE_H
