#include "paddlebonus.h"

PaddleBonus::PaddleBonus(QPointF parentPos)
    : Bonus(parentPos)
{

}
void PaddleBonus::giveBonus(Breakout *bo)
{
    Paddle *paddle = bo->paddles().values().first();
    paddle->setBonusWidth(BONUSWIDTH);
    paddle->setTimer(BONUSTIME);
}
