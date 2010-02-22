#include "bonus.h"


Bonus::Bonus(QPointF parentPos)
  : CollidingItem()
{
    setPos(parentPos);
    setRect(-BONUS_W/2, -BONUS_H/2, BONUS_W, BONUS_H);
    // rand this
    bonusType = rand() % NUM_BONUS_TYPES;
}

QRectF Bonus::boundingRect() const
{
    return rect();
}

void Bonus::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-BONUS_W/2,-BONUS_H/2,QPixmap(":/images/bonus.png"));
    painter->drawRect(rect());
}

void Bonus::advance(int step) {
    if(!step)
    {
        qDebug() << "Y: " <<  y();
        if(y() > 600)
        {
            qDebug() << "DEAD BONUS. TYPE : " << this;
            delete this;
        }
        return;
    }
    setPos(x(),y()+1);
}

Vector2D Bonus::collision(Ball const*)
{
    return Vector2D();
}

Bonus::~Bonus()
{

    qDebug() << "DEAD BONUS. TYPE : " << bonusType;

}
