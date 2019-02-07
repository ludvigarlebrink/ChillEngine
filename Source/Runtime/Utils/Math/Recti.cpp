#include "Recti.hpp"
#include "Vector2i.hpp"

namespace chill
{
Recti::Recti()
    : x(0.0f)
    , y(0.0f)
    , w(0.0f)
    , h(0.0f)
{
}

Recti::Recti(const Recti& other)
    : x(other.x)
    , y(other.y)
    , w(other.w)
    , h(other.h)
{
}

Recti::Recti(int32 x, int32 y, int32 w, int32 h)
    : x(x)
    , y(y)
    , w(w)
    , h(h)
{
}

Recti::Recti(const std::string& str)
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

std::string Recti::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}

bool Recti::contains(const Vector2i& point)
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

Recti& Recti::operator=(const Recti& other)
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
