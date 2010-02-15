#include "breakout.h"
#include <QFile>
#include <QDebug>


Breakout::Breakout()
{
}

void Breakout::paint(QPainter painter)
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
        ans = rand()%2000+1000;
    }
    return ans;
}
