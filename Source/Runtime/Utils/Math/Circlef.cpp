#include "Circlef.hpp"

namespace chill
{
Circlef::Circlef()
    : origin({ 0.0f, 0.0f } )
    , radius(0.0f)
{
}

Circlef::Circlef(const Circlef& other)
    : origin(other.origin)
    , radius(other.radius)
{
}

Circlef::Circlef(const Vector2f& origin, f32 radius)
    : origin(origin)
    , radius(radius)
{
}

Circlef::Circlef(f32 xOrigin, f32 yOrigin, f32 radius)
    : origin({ xOrigin, yOrigin })
    , radius(radius)
{
}

Circlef& Circlef::operator=(const Circlef& other)
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
