#ifndef BREAKOUTLEVELGENERATOR_H
#define BREAKOUTLEVELGENERATOR_H

#include <QList>

class Breakout;

class BreakoutLevelGenerator
{
public:
    BreakoutLevelGenerator(const int & seed);
    void generate_level(Breakout* bo);
    void add_sine(QList< QList<int> >&);
    void add_rand(QList< QList<int> >&);
    void add_bleed(QList< QList<int> >&);
protected:
    int seed;
};

#include "breakout.h"

#endif // BREAKOUTLEVELGENERATOR_H
