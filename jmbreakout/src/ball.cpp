#include "ball.h"


Ball::Ball()
{
    pos = Vector2D();
    pos.x = 10;
    pos.y = 10;
    color =  QColor(qrand() % 256, qrand() % 256, qrand() % 256);
    speed = Vector2D();
    speed.x = 1;
    speed.y = 1;
    size = 10;

}

void Ball::advance(int step)
{
   if(!step) return;
   pos += speed;

   //qDebug() << "x" << pos.x << "y" << pos.y;
   setPos(QPointF(pos.x, pos.y));
}

void Ball::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *)
{
    painter->setBrush(color);
    painter->drawEllipse(pos.x, pos.x, size, size);
    //qDebug() << "x" << pos.x << "y" << pos.y;
}