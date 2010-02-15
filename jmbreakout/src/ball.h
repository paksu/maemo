#ifndef BALL_H
#define BALL_H

#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QStyleOption>
#include <QColor>

#include "vector2d.h"

class Ball : public QGraphicsEllipseItem
{
    public:
        Ball();
        Vector2D pos;
        Vector2D speed;
        double size;
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    protected:
        void advance(int step);
    private:
        QColor color;

};

#endif // BALL_H
