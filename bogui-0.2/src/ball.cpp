#include "ball.h"
#include "breakout.h"
#include "paddle.h"
#include "buttonwidget.h"

#include <QList>
#include <typeinfo>

Ball::Ball()
  : CollidingItem()
{
    setPos(QPointF(400, 350));
    lastPos = pos();
    speed = Vector2D(3, -3);
    size = 20;
    setRect(-size/2,-size/2,size,size);
}
Ball::Ball(int x, int y)
  : CollidingItem()
{
    setPos(QPointF(x, y));
    lastPos = pos();
    speed = Vector2D(3, -3);
    size = 20;
    setRect(-size/2,-size/2,size,size);
}
void Ball::advance(int step)
{
    if(!step) {
       // Collision
       if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        }
        Breakout* bo = static_cast<Breakout*>(scene());

        if(pos().x() + size/2 > bo->w() || pos().x() - size/2 < 0 ) {
            speed.x *= -1;
        }
        if((pos().y() + size/2 > bo->h()  && bo->getGodmode()) || pos().y() - size/2 < 0) {
            speed.y *= -1;
        }

        if(pos().y() - size >  bo->h()) {
            bo->removeItem(this);
            bo->balls().remove(this);
            delete this;
        }
        if (bo->balls().isEmpty()) {
            qDebug() << "game over!!";
            bo->gameOver();
        }
    }
    else {
        lastPos = pos();
        setPos(QPointF(pos().x() + speed.x, pos().y() + speed.y));
    }
}

void Ball::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //qDebug() << "x" << pos.x << "y" << pos.y;
    painter->drawPixmap(-size/2,-size/2,QPixmap(":/images/ball.png"));

    //hitbox
    painter->drawRect(rect());
}

QRectF Ball::boundingRect() const
{
    return rect();
}

void Ball::handleCollision() {
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    Vector2D collision_sum(0.0, 0.0);
    int collision_count = 0;

    for (QList<QGraphicsItem *>::ConstIterator it = collision_list.constBegin();
        it != collision_list.constEnd(); it++) {
        Breakout* bo = static_cast<Breakout*>(scene());

        if (bo->tiles().contains(static_cast<const Tile*>(*it))
            || bo->paddles().contains(static_cast<const Paddle*>(*it)) ) {
            CollidingItem* item = static_cast<CollidingItem *>(*it);
            collision_sum += item->collision(this);
            collision_count++;
        }
    }
    if (collision_count)
    {
        qDebug() << "collision_sum_y"  << collision_sum.y;

    collision_sum /= qreal(collision_list.size());
   // collision_sum.x = -qAbs(collision_sum.x);
    //collision_sum.y *= -1;
    //qDebug() << "collision_sum_y"  << collision_sum.y;

        speed.x = collision_sum.x;
        speed.y = collision_sum.y;
    }
}
