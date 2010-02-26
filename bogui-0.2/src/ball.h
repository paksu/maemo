#ifndef BALL_H
#define BALL_H

#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QColor>
#include <QGraphicsItem>

#include "vector2d.h"
#include "collidingitem.h"

class Ball : public CollidingItem
{
    public:
        Ball();
        Ball(int x, int y);
        Vector2D speed;
        QPointF lastPos;
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
