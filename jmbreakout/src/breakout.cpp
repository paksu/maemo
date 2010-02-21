#include "breakout.h"
#include "tile.h"
#include <QFile>
#include <QDebug>
#include <math.h>


int Breakout::acc_cache = 0;
qreal Breakout::acc_expfilter_delta = 0.2;
qreal Breakout::acc_last = 0.0;

Breakout::Breakout()
{
    score = 0;
    back = new ButtonWidget(AREA_W - 25, 25, QPixmap(":images/back.png"));
    scoreText = addSimpleText(QString("0"),QFont("System", 16, QFont::Bold));
    scoreText->setPos(0,450);
    scoreText->setBrush(QBrush(QColor(255,255,255,150)));
    scoreText->setVisible(true);
    addItem(back);
    bonusTime = QTime::currentTime();
    connect(back, SIGNAL(clicked()), this, SLOT(deleteLater ()));
}

qreal Breakout::read_acc()
{
    qreal ans;
    QByteArray arr;
    QFile f("/sys/class/i2c-adapter/i2c-3/3-001d/coord");
    if (f.open(QIODevice::ReadOnly)) {
        arr = f.readLine(16);
        f.close();
        ans = -arr.left(arr.indexOf(' ')).toInt();
    } else {
        ans = ::sin((double)acc_cache++ / 100)*400;
    }
    ans = ans * acc_expfilter_delta + acc_last * (1.0 - acc_expfilter_delta);
    acc_last = ans;
    return ans;
}

int Breakout::get_w() {
    return AREA_W;
}

int Breakout::get_h() {
    return AREA_H;
}
void Breakout::addScore(int newScore) {
    qDebug() << 100 /  1 + bonusTime.secsTo(QTime::currentTime());
    score += newScore;
    score += newScore * (10 / 1 + bonusTime.secsTo(QTime::currentTime()));
    scoreText->setText(QString().number(score));
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
            this->addItem(new Tile(j,i,6-i/2, this));
        }
     }

}
