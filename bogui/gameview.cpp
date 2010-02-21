#include "gameview.h"

GameView::GameView(QWidget* parent)
    : QGraphicsView(parent)
{
    hide();
    breakout = new Breakout();
    setScene(breakout);

    setBackgroundBrush(QPixmap(":/images/bg.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

}

GameView::~GameView()
{
    delete breakout;
}

#include <QDebug>

void GameView::startGame()
{
    show();
    breakout->start();
    qDebug() << "start!!";
}
