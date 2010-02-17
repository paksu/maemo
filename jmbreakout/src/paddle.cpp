#include "paddle.h"
#include "breakout.h"

Paddle::Paddle()
        : speed(1.0), width(60.0)
{
    setRect(QRectF(0,0, width, 10));
    setPos(QPointF(400, 400));
}

void Paddle::advance(int)
{
    //setPos(QPointF(Breakout::read_acc() + 400, 400));
    setPos(QPointF(400, 400));
}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, QPixmap(":images/paddle.png"));

    //hitbox
    painter->drawRect(rect());
}
double Paddle::getSpeed() {
    return speed;
}
bool Paddle::getDirection() {
    // maybe some day..
    //return direction;
    return true;
}
