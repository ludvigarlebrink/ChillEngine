#include "Vector2u.hpp"

namespace chill
{
const Vector2u Vector2u::DOWN = Vector2u(0u, -1u);
const Vector2u Vector2u::LEFT = Vector2u(-1u, 0u);
const Vector2u Vector2u::ONE = Vector2u(1u, 1u);
const Vector2u Vector2u::RIGHT = Vector2u(1u, 0u);
const Vector2u Vector2u::UP = Vector2u(0u, 1u);
const Vector2u Vector2u::ZERO = Vector2u(0u, 0u);

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

Vector2u::Vector2u(const std::string & vec)
{
    x = std::stoi(vec.substr(vec.find_first_of("(") + 1u));
    y = std::stoi(vec.substr(vec.find_first_of(",") + 1u));
}

std::string Vector2u::toString() const
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

Vector2u& Vector2u::operator/=(const Vector2u& other)
{
    x /= other.x;
    y /= other.y;

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

Vector2u operator-(const Vector2u& vector)
{
    return { -vector.x, -vector.y };
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
