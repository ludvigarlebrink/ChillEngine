#include "Intersection2d.hpp"
#include "Circlef.hpp"

namespace chill
{
bool Intersection2d::test(const Circlef& c1, const Circlef& c2)
{
    f32 radius = c1.radius + c2.radius;
    if (radius * radius < Vector2f::distance(c1.origin, c2.origin))
    {
        return false;
    }

    return true;
}
} // namespace chill
