#include "vector2d.h"

Vector2D Vector2D::operator+=(const Vector2D& vec)
{
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}
