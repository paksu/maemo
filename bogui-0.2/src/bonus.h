#ifndef BONUS_H_
#define BONUS_H_

#define BONUS_W 25
#define BONUS_H 10
#define BONUSRATE 20
#include <QGraphicsRectItem>
#include "vector2d.h"
#include "ball.h"


class Breakout;
class Paddle;
class Tile;
class BallBonus;
class ScoreBonus;
class PaddleBonus;

class Bonus : public CollidingItem
{
public:
    Bonus(QPointF parentPos);
    ~Bonus();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    Vector2D collision(Ball const* ball);
    virtual void giveBonus(Breakout *bo) = 0;
    static void spawnBonus(QList<Bonus *> *bonuses, QPointF pos);
protected:
    void advance(int step);
private:

};

#include "breakout.h"
#include "ballbonus.h"
#include "scorebonus.h"
#include "paddlebonus.h"
#endif // BONUS_H
