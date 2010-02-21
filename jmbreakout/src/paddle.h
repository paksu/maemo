#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include "collidingItem.h"
#include "ball.h"
#include <typeinfo>

class Paddle : public CollidingItem
{
public:
    enum paddleSize { TINY = 20, NORMAL = 60, LARGE = 120 };
    Paddle();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    Vector2D collision(Ball const* ball);
    QRectF boundingRect() const;
protected:
    void advance(int phase);
private:
    double speed;
    paddleSize width;
    int timer;
    int bonusWidth;
    void handleCollision();
};

#endif // PADDLE_H
