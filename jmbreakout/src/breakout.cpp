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
