#include <QDebug>

#include "paddle.h"
#include "util.h"

#define HEIGHT 10

Paddle::Paddle(Breakout* b)
    : speed(1.0), width(Paddle::NORMAL), bonusWidth(0), timer(0)
{
    setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
    setPos(QPointF(400, 400));
    parent = b;
}

void Paddle::advance(int phase)
{
    if(!phase) {
        if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        }
        setPos(QPointF(Breakout::paddlePos, 400.0));
        //setPos(QPointF(read_acc() + 400.0, 400.0));
        return;
    }
    //setPos(QPointF(400, 400));
}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(timer && bonusWidth) {
        painter->drawPixmap(-bonusWidth/2, -HEIGHT/2, QPixmap(":images/big_paddle.png"));
        //hitbox
        painter->drawRect(rect());
        timer--;
        if(!timer) {
            setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
        }
    } else {
        painter->drawPixmap(-width/2, -HEIGHT/2, QPixmap(":images/paddle.png"));
        //hitbox
        painter->drawRect(rect());
    }
}

QRectF Paddle::boundingRect() const
{
    return rect();
}

Vector2D Paddle::collision(Ball const* ball)
{
    qDebug() << "paddle collision";
    Vector2D impulse = CollidingItem::collision(ball);
    qreal deltax = ball->x() - x();
    qDebug() << "deltax:" << deltax;
    impulse.x = (deltax/(width/2)) * 2;
    qDebug() << "impulse.x" <<  impulse.x << "impulse.y" <<  impulse.y;
    return impulse;
}
void Paddle::handleCollision() {
    Breakout *bo = static_cast<Breakout*>(scene());
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    for (QList<QGraphicsItem *>::ConstIterator it = collision_list.constBegin();
    it != collision_list.constEnd(); it++) {
    Bonus* bonus = static_cast<const Bonus*>(*it);
        if (bo->bonuses().contains(bonus))
        {
            bonus->giveBonus(bo);
            parent->removeItem(*it);
        }
     }
}
void Paddle::setBonusWidth(int _bonusWidth)
{
    bonusWidth = _bonusWidth;
}
void Paddle::setTimer(int _timer)
{
    timer = _timer;
}
