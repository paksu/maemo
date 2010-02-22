#ifndef SCOREBONUS_H
#define SCOREBONUS_H

#include "bonus.h"

class ScoreBonus : public Bonus
{
public:
    ScoreBonus(QPointF pos);
    virtual void giveBonus(Breakout *bo);
};

#endif // SCOREBONUS_H
