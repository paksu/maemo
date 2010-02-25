#include "ballbonus.h"

BallBonus::BallBonus(QPointF parentPos)
    : Bonus(parentPos)
{

}
void BallBonus::giveBonus(Breakout *bo)
{
     bo->addItem(new Ball(x(),y()-20));
}
