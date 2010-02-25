#ifndef BREAKOUTLEVELGENERATOR_H
#define BREAKOUTLEVELGENERATOR_H

class Breakout;

class BreakoutLevelGenerator
{
public:
    BreakoutLevelGenerator(const int & seed);
    void generate_level(Breakout* bo);
private:
    int seed;
};

#include "breakout.h"

#endif // BREAKOUTLEVELGENERATOR_H
