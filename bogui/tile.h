#ifndef TILE_H_
#define TILE_H_

#define TILE_W 60
#define TILE_H 10

#include <QList>
#include <QPainter>
#include "bonus.h"
#include "collidingitem.h"

class Breakout;

class Tile : public CollidingItem
{
public:
    Tile(int x, int y, int health, Breakout *b);
    ~Tile();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    Vector2D collision(Ball const* ball);
    static QList<QColor> tileColors;
protected:
    void advance(int step);
private:
    QList<Bonus *> bonuses;
    int health;
    int score;
    Breakout *parent;
};

#include "breakout.h"

#endif // TILE_H_
