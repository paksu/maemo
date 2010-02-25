#ifndef BALLBONUS_H
#define BALLBONUS_H

#include "bonus.h"

class BallBonus : public Bonus
{
public:
    BallBonus(QPointF pos);
    virtual void giveBonus(Breakout *bo);
};

#endif // BALLBONUS_H
