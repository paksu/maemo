#include "buttonwidget.h"

ButtonWidget::ButtonWidget(int x, int y, const QPixmap & pixmap)
    : pmap(pixmap)
{
    setGeometry(
        QRect(
            x-pmap.width()/2,
            y-pmap.height()/2,
            pmap.width(),
            pmap.height()
        )
    );
}

void ButtonWidget::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, pmap);
}

void ButtonWidget::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit clicked();
}

const QPixmap & ButtonWidget::pixmap()
{
    return pmap;
}
