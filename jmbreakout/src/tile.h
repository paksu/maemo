#ifndef TILE_H_
#define TILE_H_

#define TILE_W 40
#define TILE_H 10

#include <vector>
#include "bonus.h"

class Tile : public QGraphicsRectItem
{
public:
    Tile(int x, int y);

private:
    std::vector<Bonus> bonuses;
};

#endif // TILE_H_
