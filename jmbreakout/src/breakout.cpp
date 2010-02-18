#include "breakout.h"
#include <QFile>
#include <QDebug>
#include <math.h>


int Breakout::acc_cache = 0;

Breakout::Breakout()
{
}

int Breakout::read_acc()
{
    int ans;
    QByteArray arr;
    QFile f("/sys/class/i2c-adapter/i2c-3/3-001d/coord");
    if (f.open(QIODevice::ReadOnly)) {
        arr = f.readLine(16);
        f.close();
        ans = -arr.left(arr.indexOf(' ')).toInt();
    } else {
        ans = ::sin((double)acc_cache++ / 100)*400;
    }
    return ans;
}

int Breakout::get_w() {
    return AREA_W;
}

int Breakout::get_h() {
    return AREA_H;
}

void Breakout::addPaddle(Paddle *newPaddle) {
    paddle = newPaddle;
    addItem((QGraphicsRectItem*) newPaddle);
}

const Paddle & Breakout::getPaddle() {
    return *paddle;
}

void Breakout::addScore(int newScore) {
    //score += newScore;
    qDebug() << "Score is " << score;
}

int Breakout::getScore() {
    return score;
}
