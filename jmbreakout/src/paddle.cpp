#include "paddle.h"
#include "breakout.h"

Paddle::Paddle()
        : speed(0.0), width(60.0)
{
    setRect(QRectF(0,0, width, 20));
    setPos(QPointF(400, 400));
}

void Paddle::advance(int)
{
    setPos(QPointF(Breakout::read_acc() + 400, 400));
}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(-width/2, 0, width, 20);
}

QRectF Paddle::boundingRect() const
{
    return rect();
}
