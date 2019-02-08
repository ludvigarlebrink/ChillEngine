#include "Vector3u.hpp"

namespace chill
{
Vector3u::Vector3u()
    : x(0u)
    , y(0u)
    , z(0u)
{
}

Vector3u::Vector3u(const Vector3u& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
{
}

Vector3u::Vector3u(uint32 x, uint32 y, uint32 z)
    : x(x)
    , y(y)
    , z(z)
{
}

Vector3u::Vector3u(uint32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
{
}

Vector3u::Vector3u(const std::string& str)
{
    x = static_cast<uint32>(std::stoi(str.substr(str.find_first_of("(") + 1u)));
    y = static_cast<uint32>(std::stoi(str.substr(str.find_first_of(",") + 1u)));
    z = static_cast<uint32>(std::stoi(str.substr(str.find_last_of(",") + 1u)));
}

std::string Vector3u::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

Vector3u& Vector3u::operator=(const Vector3u& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    return *this;
}

Vector3u& Vector3u::operator+=(const Vector3u& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3u& Vector3u::operator-=(const Vector3u& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3u& Vector3u::operator*=(const Vector3u& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vector3u& Vector3u::operator*=(uint32 v)
{
    x *= v;
    y *= v;
    z *= v;

    return *this;
}

Vector3u& Vector3u::operator/=(const Vector3u& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

Vector3u& Vector3u::operator/=(uint32 v)
{
    x /= v;
    y /= v;
    z /= v;

    return *this;
}

uint32& Vector3u::operator[](uint32 i)
{
    return (&x)[i];
}

Vector3u operator+(const Vector3u& lhs, const Vector3u& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

Vector3u operator-(const Vector3u& lhs, const Vector3u& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

Vector3u operator*(const Vector3u& lhs, const Vector3u& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

Vector3u operator*(const Vector3u& lhs, uint32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

Vector3u operator*(uint32 lhs, const Vector3u& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

Vector3u operator/(const Vector3u& lhs, const Vector3u& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

Vector3u operator/(const Vector3u& lhs, uint32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}
} // namespace chill
