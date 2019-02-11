#include "Rectu.hpp"
#include "Vector2u.hpp"

namespace chill
{
Rectu::Rectu()
    : x(0u)
    , y(0u)
    , w(0u)
    , h(0u)
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
    x = static_cast<uint32>(std::stoi(sub));
    sub = sub.substr(sub.find_first_of(",") + 1u);
    y = static_cast<uint32>(std::stoi(sub));
    sub = sub.substr(sub.find_first_of(",") + 1u);
    w = static_cast<uint32>(std::stoi(sub));
    sub = sub.substr(sub.find_first_of(",") + 1u);
    h = static_cast<uint32>(std::stoi(sub));
}

std::string Rectu::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(w) + ", " + std::to_string(h) + ")";
}

bool Rectu::Contains(const Vector2u& point)
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
