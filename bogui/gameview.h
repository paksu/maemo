#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QWidget>

#include "breakout.h"


class GameView : public QGraphicsView
{
public:
    GameView(QWidget* parent = 0);
    ~GameView();

private:
    Breakout* breakout;

public slots:
    void startGame();

};

#endif // GAMEVIEW_H
