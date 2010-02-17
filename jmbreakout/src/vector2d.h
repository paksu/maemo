#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <QtGlobal>

typedef struct Vector2D {
    Vector2D();
    Vector2D(qreal x, qreal y);
    Vector2D operator+=(const Vector2D& vec);

    qreal x;
    qreal y;
} Vector2D;


#endif // VECTOR2D_H
