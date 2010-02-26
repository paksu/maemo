#include "util.h"

#include <QtGlobal>
#include <QDebug>
#include <QFile>
#include <math.h>

const qreal acc_expfilter_delta = 0.2;

qreal read_acc()
{
    static qreal acc_last = 0.0;
    static int acc_cache = 0;

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
