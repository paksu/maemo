#include "tile.h"

Tile::Tile(int x, int y)
{
    setPos(x * TILE_W, y * TILE_H);
    setRect(0,0,TILE_W,TILE_H);
}

void Tile::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *)
{

    painter->drawRect(rect());
}

QRectF Tile::boundingRect() const
{
    return rect();
}

int Tile::type() const
{
    return Type;
}

void Tile::collision(Ball* ball)
{

}
