#include "bonus.h"

Bonus::Bonus(QPointF parentPos)
  : CollidingItem()
{
    setPos(parentPos);
    setRect(-BONUS_W/2, -BONUS_H/2, BONUS_W, BONUS_H);
}
QRectF Bonus::boundingRect() const
{
    return rect();
}
void Bonus::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *)
{
     //qDebug() << "x" << pos.x << "y" << pos.y;
    painter->drawPixmap(-BONUS_W/2,-BONUS_H/2,QPixmap(":/images/bonus.png"));

    //hitbox
    painter->drawRect(rect());
}

void Bonus::advance(int step) {
    if(!step)
        return;
    setPos(x(),y()+1);
}

Vector2D Bonus::collision(Ball const* ball)
{
    return Vector2D();
}
