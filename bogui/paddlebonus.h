#ifndef PADDLEBONUS_H
#define PADDLEBONUS_H

#define BONUSWIDTH 60
#define BONUSTIME 500

#include "bonus.h"

class PaddleBonus : public Bonus
{
public:
    PaddleBonus(QPointF pos);
    virtual void giveBonus(Breakout *bo);
};

#endif // PADDLEBONUS_H
