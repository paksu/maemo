#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>

#include "vector2d.h"

class Breakout : public QGraphicsScene
{
public:
    Breakout();
    static int read_acc();

private:
    static int acc_cache;
};

#endif // BREAKOUT_H
