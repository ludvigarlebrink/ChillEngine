#include "Ray2d.hpp"

#include <limits>

namespace chill
{
Ray2d::Ray2d()
    : origin({ 0.0f, 0.0f })
    , direction({ 1.0f, 0.0f })
    , tMax(std::numeric_limits<f32>::digits)
{
}

Ray2d::Ray2d(const Ray2d& other)
    : origin({ 0.0f, 0.0f })
    , direction({ 1.0f, 0.0f })
    , tMax(std::numeric_limits<f32>::digits)
{
}

Ray2d::Ray2d(const Vector2f& origin, const Vector2f& direction, f32 tMax)
    : origin(origin)
    , direction(direction)
    , tMax(tMax)
{
}

Ray2d::Ray2d(const Vector2f& origin, const Vector2f& direction)
    : origin(origin)
    , direction(direction)
    , tMax(std::numeric_limits<f32>::digits)
{
}

Ray2d::Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir, f32 tMax)
    : origin({ xOrigin, yOrigin })
    , direction({ xDir, yDir })
    , tMax(tMax)
{
}

Ray2d::Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir)
    : origin({ xOrigin, yOrigin })
    , direction({ xDir, yDir })
    , tMax(std::numeric_limits<f32>::digits)
{
}

Ray2d Ray2d::operator=(const Ray2d& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        origin = other.origin;
        direction = other.direction;
        tMax = other.tMax;
    }

    return *this;
}
} // namespace chill
