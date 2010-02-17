#ifndef BALL_H
#define BALL_H

#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QStyleOption>
#include <QColor>

#include "vector2d.h"

class CollidingGraphicsItem;

class Ball : public QGraphicsEllipseItem
{
    public:
        Ball();
        Vector2D speed;
        double size;
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
        QRectF boundingRect() const;
    protected:
        void advance(int step);
    private:
        void handleCollision();
        Vector2D getCollisionNormal(QGraphicsItem const* item) const;

};

#endif // BALL_H
