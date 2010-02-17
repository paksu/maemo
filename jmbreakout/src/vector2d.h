#ifndef VECTOR2D_H
#define VECTOR2D_H

typedef struct Vector2D {
    Vector2D();
    Vector2D(double x, double y);
    Vector2D operator+=(const Vector2D& vec);
    double x;
    double y;
} Vector2D;


#endif // VECTOR2D_H
