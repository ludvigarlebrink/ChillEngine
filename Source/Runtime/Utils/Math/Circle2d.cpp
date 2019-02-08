#include "Circle2d.hpp"

namespace chill
{
Circle2d::Circle2d()
    : origin({ 0.0f, 0.0f } )
    , radius(0.0f)
{
}

Circle2d::Circle2d(const Circle2d& other)
    : origin(other.origin)
    , radius(other.radius)
{
}

Circle2d::Circle2d(const Vector2f& origin, f32 radius)
    : origin(origin)
    , radius(radius)
{
}

Circle2d::Circle2d(f32 xOrigin, f32 yOrigin, f32 radius)
    : origin({ xOrigin, yOrigin })
    , radius(radius)
{
}

Circle2d& Circle2d::operator=(const Circle2d& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        origin = other.origin;
        radius = other.radius;
    }

    return *this;
}
} // namespace chill
