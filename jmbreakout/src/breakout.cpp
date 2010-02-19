#include "breakout.h"
#include "tile.h"
#include <QFile>
#include <QDebug>
#include <math.h>


int Breakout::acc_cache = 0;

Breakout::Breakout()
{
    score = 0;
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
void Breakout::addScore(int newScore) {
    score += newScore;
    qDebug() << "Score is " << score;
}
int Breakout::getScore() {
    return score;
}
void Breakout::generateLevel(int seed) {
     int width = AREA_W;
     int rows = 10;

     for(int i = rows;i > 0;i--) {
         for(int j = 1;j < (width/60);j++) {
            this->addItem(new Tile(j,i,5-i/2, this));
        }
     }

}
