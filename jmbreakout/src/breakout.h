#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTime>

#include "vector2d.h"
#include "buttonwidget.h"

#define AREA_W 800
#define AREA_H 480

class Breakout : public QGraphicsScene
{
Q_OBJECT
public:
    Breakout();
    static qreal read_acc();
    static qreal mousePos;
    static int get_w();
    static int get_h();
    int getScore();
    void addScore(int score);
    void generateLevel(int seed);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
    static int acc_cache;
    static qreal acc_expfilter_delta;
    static qreal acc_last;
    int score;
    ButtonWidget* back;
    QGraphicsSimpleTextItem* scoreText;
    QTime bonusTime;
};

#endif // BREAKOUT_H
