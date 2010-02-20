#ifndef BONUS_H_
#define BONUS_H_

#define BONUS_W 25
#define BONUS_H 10

#include <QGraphicsRectItem>
#include "vector2d.h"
#include "ball.h"

class Bonus : public CollidingItem
{
public:
    Bonus(QPointF parentPos);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *);
    Vector2D collision(Ball const* ball);
protected:
    void advance(int step);
private:
};

#endif // BONUS_H
