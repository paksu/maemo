#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include "colliding.h"

class Paddle : public QGraphicsRectItem, public Colliding
{
public:
    Paddle();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    double getSpeed();
    bool getDirection();
    Vector2D collision(Ball const* ball);
    QRectF boundingRect() const;
protected:
    void advance(int phase);
private:
    double speed, width;
    bool direction;
};

#endif // PADDLE_H
