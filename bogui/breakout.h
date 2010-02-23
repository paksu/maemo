#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QTime>
#include <QSet>

#include "tile.h"
#include "buttonwidget.h"
#include "gameview.h"

#include "ball.h"
#include "paddle.h"
#include "bonus.h"

class GameView;

class Breakout : public QGraphicsScene
{
    Q_OBJECT
public:
    Breakout(GameView* theView);
    ~Breakout();
    void init();
    void start();
    void stop();
    void addPaddle();
    void addBall();
    void addBonus(Bonus *);
    void generateLevel(const int & seed);
    void deletePaddles();
    void deleteBalls();
    void deleteTiles();
    void setGodmode(bool godmode_);
    void setControlMethod(bool controlMethod_);
    bool getGodmode();
    bool getControlMethod();
    QSet<Tile*>  & tiles();
    QSet<Paddle*> & paddles();
    QSet<Bonus*> & bonuses();
    QSet<Ball*> & balls();

    static qreal read_acc();
    int getScore();
    void addScore(int score);
    qreal w() const;
    qreal h() const;

    static qreal paddlePos;

private:
    QTimer* tick_timer;

    QSet<Ball*> balls_;
    QSet<Tile*> tiles_;
    QSet<Paddle*> paddles_;
    QSet<Bonus*> bonuses_;

    GameView* theView;

    int score;
    ButtonWidget* back;
    QGraphicsSimpleTextItem* scoreText;
    QTime bonusTime;

    bool godmode;
    bool controlMethod;


protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // BREAKOUT_H
