#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <QTime>
#include <QSet>

#include "tile.h"
#include "buttonwidget.h"

#include "ball.h"
#include "tile.h"
#include "paddle.h"
#include "bonus.h"

class Breakout : public QGraphicsScene
{
    Q_OBJECT
public:
    Breakout();
    ~Breakout();
    void init();
    void start();
    void addPaddle();
    void addBall();
    void generateLevel(const int & seed);
    const QSet<Tile*>  & tiles();
    const QSet<Paddle*> & paddles();

    static qreal read_acc();
    int getScore();
    void addScore(int score);
private:
    QTimer* tick_timer;
    QSet<Ball*> balls_;
    QSet<Tile*> tiles_;
    QSet<Paddle*> paddles_;
    QSet<Bonus*> bonuses_;


    static int acc_cache;
    static qreal acc_expfilter_delta;
    static qreal acc_last;
    int score;
    ButtonWidget* back;
    QGraphicsSimpleTextItem* scoreText;
    QTime bonusTime;
};

#endif // BREAKOUT_H
