#include "ball.h"
#include "breakout.h"
#include "paddle.h"

Ball::Ball()
{
    pos = Vector2D();
    pos.x = 400;
    pos.y = 230;
    speed = Vector2D();
    speed.x = 0;
    speed.y = 1;
    size = 20;
    setRect(0,0,size,size);

}

void Ball::advance(int step)
{
    if(!step) {
       // Collision
       if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        } else {

           // demo
           if(pos.x + size/2 > Breakout::get_w() || pos.x < 0 ) {
               speed.x *= -1;
           }
           if(pos.y + size/2 > Breakout::get_h() || pos.y < 0) {
               speed.y *= -1;
           }
        }
        return;
    }
   pos += speed;
   //qDebug() << "x" << pos.x << "y" << pos.y;
   //foobar
   setPos(QPointF(pos.x, pos.y));
}

void Ball::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *)
{
    //qDebug() << "x" << pos.x << "y" << pos.y;
    painter->drawPixmap(0,0,QPixmap(":/images/ball.png"));

    //hitbox
    painter->drawRect(rect());
}

QRectF Ball::boundingRect() const
{
    return rect();
}

void Ball::handleCollision() {
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    // Determine which side was hit
    Paddle* p = (Paddle*)collision_list.first();
    QRectF c_size = collision_list.first()->boundingRect();
    QPointF c_pos = collision_list.first()->pos();

    if((pos.y + size) == c_pos.y()) {
        //qDebug() << "paddle ylälaita, pallon alalaita";
        speed.y *= -1;
    } else if(pos.y == (c_pos.y() + c_size.height())) {
        //qDebug() << "paddle alalaita, pallon ylälaitalaita";
        speed.y *= -1;
    }

    if(pos.x == (c_pos.x() + c_size.width())) {
        //qDebug() << "paddle oikea laita, pallon vasen laita";

        qDebug() << (pos.x + (size/2)) << c_pos.x() << c_size.width();
        p->getDirection() ? speed.x -= p->getSpeed() : speed.x += p->getSpeed();
        speed.x *= -1;

    } else if((pos.x + size)== c_pos.x()) {
        //qDebug() << "paddle vasen laita, pallon oikea laita";
        qDebug() << (pos.x + size) << c_pos.x() << c_size.width();
        p->getDirection() ? speed.x += p->getSpeed() : speed.x -= p->getSpeed();
        speed.x *= -1;
    }

}
