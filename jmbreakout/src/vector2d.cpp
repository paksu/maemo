#ifndef VECTOR2D_
#define VECTOR2D_

#include "vector2d.h"

Vector2D::Vector2D()
    : x(0),y(0)
{}

Vector2D::Vector2D(qreal x, qreal y)
    : x(x), y(y)
{}

Vector2D Vector2D::operator+=(const Vector2D& vec)
{
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}


#endif
