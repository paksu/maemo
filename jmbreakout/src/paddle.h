#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>

class Paddle : public QGraphicsRectItem
{
public:
    Paddle();
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    double getSpeed();
    bool getDirection();
protected:
    void advance(int phase);
private:
    double speed, width;
    bool direction;
};

#endif // PADDLE_H
