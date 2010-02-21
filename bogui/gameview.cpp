#include "gameview.h"

GameView::GameView(QWidget* parent)
    : QGraphicsView(parent)
{
    hide();
    breakout = new Breakout();
    setSceneRect(0,0, width(), height());
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
    show();
    breakout->start();
}
