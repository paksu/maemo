#include "tile.h"

Tile::Tile(int x, int y)
{
    setPos(x * TILE_W, y * TILE_H);
    setRect(TILE_W/2, TILE_H/2,TILE_W,TILE_H);
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

Vector2D Tile::collision(Ball const* ball)
{
    return CollidingItem::collision(ball);
}
