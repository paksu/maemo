#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <QtGlobal>
#include <QString>

struct Vector2D {
    Vector2D();
    Vector2D(qreal x, qreal y);
    Vector2D operator += (const Vector2D& vec);
    Vector2D operator /= (const qreal& real);
    Vector2D operator *= (const qreal& real);

    qreal x;
    qreal y;
};


#endif // VECTOR2D_H
