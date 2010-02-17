#include "tile.h"

Tile::Tile(int x, int y)
{
    setPos(x * TILE_W, y * TILE_H);
    setRect(0,0,TILE_W,TILE_H);
}

void Tile::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
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

Vector2D Tile::collision(Ball const*)
{
    return Vector2D(.0, .0);
}
