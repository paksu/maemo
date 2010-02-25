#include "breakoutlevelgenerator.h"

#include "tile.h"

BreakoutLevelGenerator::BreakoutLevelGenerator(const int & seed)
    : seed(seed)
{ }

// XXX : implementation!! ´_`
void BreakoutLevelGenerator::generate_level(Breakout* bo)
{
    int s = seed;
    if (s == 0) {
        for (int i = 8;i > 0;i--) {
            for (int j = 1;j < (bo->width()/60);j++) {
                Tile* t = new Tile(j,i,6-i/2, bo);
                bo->tiles() += t;
                bo->addItem(t);
            }
        }
        return;
    }

    switch(s % 2) {
        case 0:
        break;
    }
}
