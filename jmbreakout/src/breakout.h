#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QPainter>

#endif // BREAKOUT_H


class Breakout : public QGraphicsScene
{
    public:
        Breakout();
        void paint(QPainter painter);

    protected:
        int read_acc();
    private:
};
