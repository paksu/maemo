#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QWidget>

#include "breakout.h"


class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget* parent = 0);
    ~GameView();

private:
    Breakout* breakout;

public slots:
    void startGame();
    void stopGame();

signals:
    void gameStopped();
};

#endif // GAMEVIEW_H
