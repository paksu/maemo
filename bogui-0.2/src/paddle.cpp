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
    pmap1 = QPixmap(":images/paddle.png");
    pmap2 = QPixmap(":images/big_paddle.png");
}

void Paddle::advance(int phase)
{
    if(!phase) {
        if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        }
        return;
    }

    QPointF last = this->pos();
    qreal nextPos = breakout()->controlMethod ? nextPos = Breakout::paddlePos :  nextPos = read_acc() + 400;
    Breakout *b = static_cast<Breakout *>(scene());
    nextPos = nextPos < width/2 ? width/2 : nextPos;
    nextPos = (nextPos + width/2) > b->w() ? (b->w() - width/2) : nextPos;

    setPos(QPointF(nextPos, 400.0));

    if(!scene()->collidingItems(this).isEmpty()) {
        setPos(last);
    }

}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(timer && bonusWidth) {
        painter->drawPixmap(-bonusWidth/2, -HEIGHT/2, pmap2);
        timer--;
        if(!timer) {
            setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
        }
    } else {
        painter->drawPixmap(-width/2, -HEIGHT/2, pmap1);
    }
}

QRectF Paddle::boundingRect() const
{
    return rect();
}

Vector2D Paddle::collision(Ball const* ball)
{
    Vector2D impulse = CollidingItem::collision(ball);
    qreal deltax = ball->x() - x();
    impulse.x = (deltax/(width/2)) * (ball->speed.x + 2);
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
