#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>

#include "vector2d.h"
#include "paddle.h"

#define AREA_W 800
#define AREA_H 480

class Breakout : public QGraphicsScene
{
public:
    Breakout();
    static int read_acc();
    static int get_w();
    static int get_h();
    const Paddle & getPaddle();
    void addPaddle(Paddle *paddle);
    int getScore();
    void addScore(int score);
private:
    static int acc_cache;
    Paddle *paddle;
    int score;

};

#endif // BREAKOUT_H
