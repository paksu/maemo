#include "scorebonus.h"

ScoreBonus::ScoreBonus(QPointF parentPos)
    : Bonus(parentPos)
{

}
void ScoreBonus::giveBonus(Breakout *bo)
{
     bo->addScore(10000);
}
