#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSimpleTextItem>
#include <QTime>


class Breakout : public QGraphicsScene
{
    Q_OBJECT
public:
    Breakout();
    void init();
    void start();


    static qreal read_acc();
    static int get_w();
    static int get_h();
    int getScore();
    void addScore(int score);
    void generateLevel(int seed);
private:
    static int acc_cache;
    static qreal acc_expfilter_delta;
    static qreal acc_last;
    int score;
    //ButtonWidget* back;
    QGraphicsSimpleTextItem* scoreText;
    QTime bonusTime;
};

#endif // BREAKOUT_H
