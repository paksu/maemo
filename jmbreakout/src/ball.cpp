#include "ball.h"
#include "breakout.h"
#include "paddle.h"


#include <QList>

Ball::Ball()
{
    setPos(QPointF(200, 180));
    speed = Vector2D(1, 1);
    size = 20;
    setRect(-size/2,-size/2,size,size);
}

void Ball::advance(int step)
{
    if(!step) {
       // Collision
       if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        } else {

           // demo
           if(pos().x() + size/2 > Breakout::get_w() || pos().x() < 0 ) {
               speed.x *= -1;
           }
           if(pos().y() + size/2 > Breakout::get_h() || pos().y() < 0) {
               speed.y *= -1;
           }
        }
        return;
    }
    else {
        //qDebug() << "x" << pos.x << "y" << pos.y;
        //foobar
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

#include "colliding.h"

void Ball::handleCollision() {
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    Vector2D collision_sums();

    for (QList<QGraphicsItem *>::ConstIterator it = collision_list.constBegin();
        it != collision_list.constEnd(); it++) {

        Vector2D coll_normal = getCollisionNormal(*it);
        qDebug() << speed.x << " " << speed.y << " | " << coll_normal.x << " : " << coll_normal.y;
        if (coll_normal.x > 0.0)
            speed.x = qAbs(speed.x);
        if (coll_normal.x < 0.0)
            speed.x = -qAbs(speed.x);

        if (coll_normal.y > 0.0)
            speed.y = qAbs(speed.y);
        if (coll_normal.y < 0.0)
            speed.y = -qAbs(speed.y);

        Colliding* item = dynamic_cast<Colliding *>(*it);
        speed += item->collision(this);
    }
}


Vector2D Ball::getCollisionNormal(QGraphicsItem const* item) const
{
    const QRectF target_size = item->boundingRect();
    const QPointF target_pos = item->pos();

    qDebug() << pos() << " || " << " :: " << target_size << " : " << target_pos;

    qreal dir_x = 0.0, dir_y = 0.0;
    const qreal x1 = pos().x(), x2 = target_pos.x();
    const qreal y1 = pos().y(), y2 = target_pos.y();
    const qreal w = (target_size.width() + rect().width())/2;
    const qreal h = (target_size.height() + rect().height())/2;

    if ( w <= qAbs(x1 - x2) && h > qAbs(y1 - y2) ) {
        qDebug() << 1;
        // collision to side
        dir_x = x1 < x2 ? -1.0 : 1.0;
    }
    else if ( h <= qAbs(y1 - y2) && w > qAbs(x1 - x2) ) {
        qDebug() << 2;
        // collision to top / bottom
        dir_y = y1 < y2 ? -1.0 : 1.0;
    }
    else {
        qDebug() << 3;
        // collision to corner
        dir_x = x1 < x2 ? -1.0 : 1.0;
        dir_y = y1 < y2 ? -1.0 : 1.0;
    }

    return Vector2D(dir_x, dir_y);
}
