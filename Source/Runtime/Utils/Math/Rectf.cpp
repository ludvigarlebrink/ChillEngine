#include "Rectf.hpp"

namespace chill
{
Rectf::Rectf()
    : x(0.0f)
    , y(0.0f)
    , w(0.0f)
    , h(0.0f)
{
}

Rectf::Rectf(const Rectf& other)
    : x(other.x)
    , y(other.y)
    , w(other.w)
    , h(other.h)
{
}

Rectf::Rectf(f32 x, f32 y, f32 w, f32 h)
    : x(x)
    , y(y)
    , w(w)
    , h(h)
{
}

Rectf::Rectf(const std::string& str)
{
}

std::string Rectf::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}

bool Rectf::contains(const Vector2f & point)
{
    return false;
}

Rectf& Rectf::operator=(const Rectf& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        w = other.w;
        h = other.h;
    }

    return *this;
}
} // namespace chill
