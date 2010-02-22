#include "gameview.h"

GameView::GameView(QWidget* parent)
    : QGraphicsView(parent)
{
    hide();
    breakout = new Breakout(this);
    setGeometry(0, 0, 800, 480);
    setSceneRect(0,0, 800, 480);
    setScene(breakout);

    setBackgroundBrush(QPixmap(":/images/bg.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

GameView::~GameView()
{
    delete breakout;
}

void GameView::startGame()
{
    breakout->init();
    breakout->start();
}

void GameView::stopGame()
{
    breakout->stop();
    emit gameStopped();
}
