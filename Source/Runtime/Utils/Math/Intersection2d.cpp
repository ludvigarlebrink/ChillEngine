#include "Intersection2d.hpp"
#include "AABounds2d.hpp"
#include "Circle2d.hpp"

namespace chill
{
bool Intersection2d::test(const AABounds2d& a, const AABounds2d& b)
{
    if (a.max.x < b.min.x || a.min.x > b.max.x)
    {
        return false;
    }

    if (a.max.y < b.min.y || a.min.y > b.max.y)
    {
        return false;
    }

    return true;
}
bool Intersection2d::test(const Circle2d& a, const Circle2d& b)
{
    f32 radius = a.radius + b.radius;
    if (radius * radius < Vector2f::distance(a.origin, b.origin))
    {
        return false;
    }

    return true;
}
} // namespace chill
