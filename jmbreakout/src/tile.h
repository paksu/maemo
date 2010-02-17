#ifndef TILE_H_
#define TILE_H_

#define TILE_W 40
#define TILE_H 10

#include <vector>
#include <QPainter>
#include "bonus.h"

class Tile : public QGraphicsRectItem
{
public:
    Tile(int x, int y);
    int type() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    QRectF boundingRect() const;
private:
    std::vector<Bonus> bonuses;
    enum { Type = UserType +1 };
};

#endif // TILE_H_
