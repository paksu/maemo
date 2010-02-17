#ifndef TILE_H_
#define TILE_H_

#define TILE_W 60
#define TILE_H 10

#include <vector>
#include <QPainter>
#include "bonus.h"
#include "colliding.h"

class Tile : public QGraphicsRectItem, public Collidable
{
public:
    Tile(int x, int y);
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    void collision(Ball* ball);
private:
    std::vector<Bonus> bonuses;
    enum { Type = UserType +1 };
};

#endif // TILE_H_
