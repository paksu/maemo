#include "ball.h"
#include "breakout.h"
#include "paddle.h"


#include <QList>

Ball::Ball()
  : CollidingItem()
{
    setPos(QPointF(220, 180));
    speed = Vector2D(1, 3);
    size = 20;
    setRect(-size/2,-size/2,size,size);
}
Ball::Ball(int x, int y)
  : CollidingItem()
{
    setPos(QPointF(x, y));
    speed = Vector2D(1, 3);
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
#include <typeinfo>
#include "buttonwidget.h"

void Ball::handleCollision() {
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    Vector2D collision_sum(0.0, 0.0);

    for (QList<QGraphicsItem *>::ConstIterator it = collision_list.constBegin();
        it != collision_list.constEnd(); it++) {

        if (typeid(**it) != typeid(ButtonWidget) && typeid(**it) != typeid(QGraphicsSimpleTextItem) ) {
            CollidingItem* item = static_cast<CollidingItem *>(*it);
            collision_sum += item->collision(this);
        }
    }
    collision_sum /= qreal(collision_list.size());
    collision_sum.x = -qAbs(collision_sum.x);
    collision_sum.y = -qAbs(collision_sum.y);
    if (collision_sum.x < -0.1)
        speed.x *= collision_sum.x;
    if (collision_sum.y < -0.1)
        speed.y *= collision_sum.y;
}
