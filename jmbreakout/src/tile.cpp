#include "tile.h"
#include "breakout.h"

Tile::Tile(int x, int y, int health, Breakout *b)
{
    setPos(x * TILE_W, y * TILE_H);
    setRect(0,0,TILE_W,TILE_H);
    this->health = health;
    score = 100*health;
    parent = b;
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
    health--;
    return Vector2D(.0, .0);
}
void Tile::advance(int step)
{
    if(!step)
        return;
    if(health <= 0){
        parent->addScore(score);
        scene()->removeItem(this);
        delete this;
    }
}
void Tile::setParent(Breakout *b) {
    qDebug() << parent;
    parent = b;
}
Tile::~Tile() {
    parent = NULL;
    qDebug() << "GOOD BYE CRUEL WORLD";
}
