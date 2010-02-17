#ifndef TILE_H_
#define TILE_H_

#define TILE_W 60
#define TILE_H 10

#include <QList>
#include <QPainter>
#include "bonus.h"
#include "colliding.h"

class Tile : public QGraphicsRectItem, public Colliding
{
public:
    Tile(int x, int y);
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    Vector2D collision(Ball const* ball);
private:
    QList<Bonus> bonuses;
    enum { Type = UserType +1 };
};

#endif // TILE_H_
