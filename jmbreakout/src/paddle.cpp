#include <QDebug>

#include "paddle.h"
#include "breakout.h"

#define HEIGHT 10

Paddle::Paddle()
    : speed(1.0), width(60.0)
{
    setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
    setPos(QPointF(400, 400));
}

void Paddle::advance(int)
{
    //setPos(QPointF(Breakout::read_acc() + 400, 400));
    setPos(QPointF(400, 400));
}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-width/2, -HEIGHT/2, QPixmap(":images/paddle.png"));

    //hitbox
    painter->drawRect(rect());
}

QRectF Paddle::boundingRect() const
{
    return rect();
}

Vector2D Paddle::collision(Ball const* ball)
{
    const qreal x1 = pos().x(), x2 = ball->pos().x();

    qDebug() << "paddle collision";
    Vector2D impulse = CollidingItem::collision(ball);
    //impulse.x += (x1 - x2) / 5.0;
    return impulse;
}
