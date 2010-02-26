#include "paddlebonus.h"

PaddleBonus::PaddleBonus(QPointF parentPos)
    : Bonus(parentPos)
{

}
void PaddleBonus::giveBonus(Breakout *bo)
{
    Paddle *paddle = bo->paddles().values().first();
    qDebug() << paddle;
    paddle->setRect(QRectF(-BONUSWIDTH/2, -BONUSHEIGHT/2, BONUSWIDTH, BONUSHEIGHT));
    paddle->setBonusWidth(BONUSWIDTH);
    paddle->setTimer(BONUSTIME);
}
