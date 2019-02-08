#include "AABounds2d.hpp"

namespace chill
{
AABounds2d::AABounds2d()
    : max({ 0.0f, 0.0f })
    , min({ 0.0f, 0.0f })
{
}

AABounds2d::AABounds2d(const AABounds2d& other)
    : max(other.max)
    , min(other.min)
{
}

AABounds2d::AABounds2d(const Vector2f& max, const Vector2f& min)
    : max(max)
    , min(min)
{
}

AABounds2d& AABounds2d::operator=(const AABounds2d& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        max = other.max;
        min = other.min;
    }

    return *this;
}
} // namespace chill
