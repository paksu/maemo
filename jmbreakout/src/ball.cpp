#include "ball.h"
#include "breakout.h"

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
   // demo
   if(pos.x > Breakout::get_w() ||pos.x < 0 ) {
       speed.x *= -1;
   }

   if(pos.y > Breakout::get_h() || pos.y < 0){
       speed.y *= -1;
   }

   qDebug() << "x" << pos.x << "y" << pos.y;
   setPos(QPointF(pos.x, pos.y));
}

void Ball::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *)
{
    painter->setBrush(color);
    painter->drawEllipse(0, 0, size, size);
    //qDebug() << "x" << pos.x << "y" << pos.y;
}
