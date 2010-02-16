#ifndef VECTOR2D_H
#define VECTOR2D_H

typedef struct Vector2D {
    Vector2D() : x(0),y(0) {}
    Vector2D operator+=(const Vector2D& vec);
    double x;
    double y;
} Vector2D;


#endif // VECTOR2D_H
