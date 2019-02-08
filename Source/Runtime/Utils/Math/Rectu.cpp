#include "Rectu.hpp"
#include "Vector2u.hpp"

namespace chill
{
Rectu::Rectu()
    : x(0.0f)
    , y(0.0f)
    , w(0.0f)
    , h(0.0f)
{
}

Rectu::Rectu(const Rectu& other)
    : x(other.x)
    , y(other.y)
    , w(other.w)
    , h(other.h)
{
}

Rectu::Rectu(uint32 x, uint32 y, uint32 w, uint32 h)
    : x(x)
    , y(y)
    , w(w)
    , h(h)
{
}

Rectu::Rectu(const std::string& str)
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

std::string Rectu::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}

bool Rectu::contains(const Vector2u& point)
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

Rectu& Rectu::operator=(const Rectu& other)
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
