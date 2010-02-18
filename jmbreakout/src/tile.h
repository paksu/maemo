#ifndef TILE_H_
#define TILE_H_

#define TILE_W 60
#define TILE_H 10

#include <QList>
#include <QPainter>
#include "bonus.h"
#include "breakout.h"
#include "collidingItem.h"

class Tile : public CollidingItem
{
public:
    Tile(int x, int y, int health, Breakout *b);
    ~Tile();
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    Vector2D collision(Ball const* ball);
    void setParent(Breakout *b);
protected:
    void advance(int step);
private:
    QList<Bonus> bonuses;
    enum { Type = UserType +1 };
    int health;
    int score;
    Breakout *parent;
};

#endif // TILE_H_
