#include "paddlebonus.h"

PaddleBonus::PaddleBonus(QPointF parentPos)
    : Bonus(parentPos)
{

}
void PaddleBonus::giveBonus(Breakout *bo)
{
    Paddle *paddle = bo->paddles().values().first();
    qDebug() << paddle;
    qDebug() << "paddle->boundingRect();" << paddle->boundingRect();
    paddle->setRect(QRectF(-BONUSWIDTH/2, -BONUSHEIGHT/2, BONUSWIDTH, BONUSHEIGHT));
    qDebug() << "paddle->boundingRect();" << paddle->boundingRect();
    paddle->setBonusWidth(BONUSWIDTH);
    paddle->setTimer(BONUSTIME);
}
