#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QGraphicsWidget>

class ButtonWidget : public QGraphicsWidget
{
Q_OBJECT

public:
    ButtonWidget(int x, int y, const QPixmap & image);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *);
    const QPixmap & pixmap();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event );
private:
    QPixmap pmap;

signals:
    void clicked();
};

#endif // BUTTONWIDGET_H
