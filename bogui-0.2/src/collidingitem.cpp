#include "collidingitem.h"

CollidingItem::CollidingItem()
    : QGraphicsRectItem() {}

Vector2D CollidingItem::collision(Ball const* ball)
{
    const QRectF target_size = ball->boundingRect();
    const QPointF target_pos = ball->pos();



    qreal dir_x = 0.0, dir_y = 0.0;
    const qreal x1 = pos().x(), x2 = target_pos.x();
    const qreal y1 = pos().y(), y2 = target_pos.y();
    const qreal w = (target_size.width() + rect().width())/2;
    const qreal h = (target_size.height() + rect().height())/2;

    qDebug() << pos() << " || " << " :: " << target_size << " : " << target_pos << " || " << w << " " << h << " " << qAbs(x1 - x2) << " " << qAbs(y1 - y2);

    if ( (w > qAbs(ball->lastPos.x() - x1)) && (w <= qAbs(x1 - x2))) {
        qDebug() << 1;
        // collision to side
        dir_x = x1 < x2 ? 1.0 : -1.0;
    }
    else /* ( h <= qAbs(y1 - y2) && (h > qAbs(ball->lastPos.y() - y1)) ) */ {
        qDebug() << 2;
        // collision to top / bottom
        dir_y = y1 < y2 ? 1.0 : -1.0;
    } /*
    else {
        qDebug() << 3;
        // collision to corner
        dir_x = x1 < x2 ? 1.0 : -1.0;
        dir_y = y1 < y2 ? 1.0 : -1.0;
    }*/

    return Vector2D(dir_x, dir_y);
}

Breakout* CollidingItem::breakout()
{
    return static_cast<Breakout*>(scene());
}
