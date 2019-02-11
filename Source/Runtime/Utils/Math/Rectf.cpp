#include "Rectf.hpp"
#include "Vector2f.hpp"

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
    std::string sub = str.substr(str.find_first_of("(") + 1u);
    x = std::stof(sub);
    sub = sub.substr(sub.find_first_of(",") + 1u);
    y = std::stof(sub);
    sub = sub.substr(sub.find_first_of(",") + 1u);
    w = std::stof(sub);
    sub = sub.substr(sub.find_first_of(",") + 1u);
    h = std::stof(sub);
}

std::string Rectf::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}

bool Rectf::Contains(const Vector2f& point)
{
    if (x > point.x || y > point.y)
    {
        return false;
    }

    if (x + w < point.x || y + h < point.y)
    {
        return false;
    }

    return true;
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
