#include "tile.h"

Tile::Tile(int x, int y)
{
    setPos(x * TILE_W, y * TILE_H);
}
