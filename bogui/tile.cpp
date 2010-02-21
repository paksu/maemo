#include "tile.h"

QList<QColor> Tile::tileColors = QList<QColor>();

Tile::Tile(int x, int y, int health, Breakout *b)
{
    setPos(x * TILE_W, y * TILE_H);
    setRect(-TILE_W/2, -TILE_H/2,TILE_W,TILE_H);
    this->health = health;
    score = health;
    parent = b;
    if(tileColors.size() == 0) {
        tileColors.append(QColor(255,210,0,255));
        tileColors.append(QColor(255,90,0,255));
        tileColors.append(QColor(50,200,0,255));
        tileColors.append(QColor(75,0,200,255));
        tileColors.append(QColor(60,50,0,255));
        tileColors.append(QColor(0,60,60,255));
        tileColors.append(QColor(255,210,0,255));
        tileColors.append(QColor(255,90,0,255));
        tileColors.append(QColor(50,200,0,255));
        tileColors.append(QColor(75,0,200,255));
        tileColors.append(QColor(60,50,0,255));
        tileColors.append(QColor(0,60,60,255));
    }
    if(!(rand() % 5))   // 20% chance for a bonus
        bonuses.append(new Bonus(pos()));
}

void Tile::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Tile::tileColors.at(score));
    painter->drawRect(rect());
}

QRectF Tile::boundingRect() const
{
    return rect();
}

Vector2D Tile::collision(Ball const* ball)
{
    health--;
    return CollidingItem::collision(ball);
}
void Tile::advance(int step)
{
    if(!step)
        return;
    if(health <= 0){
        parent->addScore(score * 1000);
        scene()->removeItem(this);
        if(bonuses.size()) {
            for (QList<Bonus *>::ConstIterator it = bonuses.constBegin();
                it != bonuses.constEnd(); it++) {
                parent->addItem(static_cast<Bonus *>(*it));
            }
        }
        delete this;
    }
}
