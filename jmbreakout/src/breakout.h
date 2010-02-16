#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>

#include "vector2d.h"

#define AREA_W 800
#define AREA_H 480

class Breakout : public QGraphicsScene
{
public:
    Breakout();
    static int read_acc();
    static int get_w();
    static int get_h();

private:
    static int acc_cache;
};

#endif // BREAKOUT_H
