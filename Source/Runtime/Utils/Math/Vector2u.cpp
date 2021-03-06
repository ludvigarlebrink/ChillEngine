#include "Vector2u.hpp"

namespace chill
{
Vector2u::Vector2u()
    : x(0u)
    , y(0u)
{
}

Vector2u::Vector2u(const Vector2u& other)
    : x(other.x)
    , y(other.y)
{
}

Vector2u::Vector2u(uint32 x, uint32 y)
    : x(x)
    , y(y)
{
}

Vector2u::Vector2u(uint32 uniform)
    : x(uniform)
    , y(uniform)
{
}

Vector2u::Vector2u(const std::string& str)
{
    x = static_cast<uint32>(std::stoi(str.substr(str.find_first_of("(") + 1u)));
    y = static_cast<uint32>(std::stoi(str.substr(str.find_first_of(",") + 1u)));
}

std::string Vector2u::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2u& Vector2u::operator=(const Vector2u& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }

    return *this;
}

Vector2u& Vector2u::operator+=(const Vector2u& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2u& Vector2u::operator-=(const Vector2u& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2u& Vector2u::operator*=(const Vector2u& other)
{
    x *= other.x;
    y *= other.y;

    return *this;
}

Vector2u& Vector2u::operator*=(uint32 v)
{
    x *= v;
    y *= v;

    return *this;
}

Vector2u& Vector2u::operator/=(const Vector2u& other)
{
    x /= other.x;
    y /= other.y;

    return *this;
}

Vector2u& Vector2u::operator/=(uint32 v)
{
    x /= v;
    y /= v;

    return *this;
}

uint32& Vector2u::operator[](uint32 i)
{
    return (&x)[i];
}

Vector2u operator+(const Vector2u& lhs, const Vector2u& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

Vector2u operator-(const Vector2u& lhs, const Vector2u& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Vector2u operator*(const Vector2u& lhs, const Vector2u& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y };
}

Vector2u operator*(const Vector2u& lhs, uint32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs };
}

Vector2u operator*(uint32 lhs, const Vector2u& rhs)
{
    return { lhs * rhs.y, lhs * rhs.y };
}

Vector2u operator/(const Vector2u& lhs, const Vector2u& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y };
}

Vector2u operator/(const Vector2u& lhs, uint32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs };
}
} // namespace chill
