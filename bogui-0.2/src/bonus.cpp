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

void Bonus::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-BONUS_W/2,-BONUS_H/2,QPixmap(":/images/bonus.png"));
    painter->drawRect(rect());
}

void Bonus::advance(int step) {
    if(!step)
    {
        Breakout *b = static_cast <const Breakout*>(scene());
        if(y() > b->h())
        {
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
void Bonus::spawnBonus(QList<Bonus *> *bonuses, QPointF pos) {
    switch(rand()%BONUSRATE) {
        case 0:
            bonuses->append(new BallBonus(pos));
            break;
        case 1:
            bonuses->append(new PaddleBonus(pos));
            break;
        case 2:
            bonuses->append(new ScoreBonus(pos));
            break;
    }
}

Bonus::~Bonus()
{
}
