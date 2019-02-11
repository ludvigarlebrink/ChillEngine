#include "Vector4u.hpp"

namespace chill
{
Vector4u::Vector4u()
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector4u::Vector4u(const Vector4u& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(other.w)
{
}

Vector4u::Vector4u(uint32 x, uint32 y, uint32 z, uint32 w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector4u::Vector4u(uint32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
    , w(uniform)
{
}

Vector4u::Vector4u(const std::string& vec)
{
}

std::string Vector4u::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}

Vector4u& Vector4u::operator=(const Vector4u& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
    }

    return *this;
}

Vector4u& Vector4u::operator+=(const Vector4u& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}

Vector4u& Vector4u::operator-=(const Vector4u& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}

Vector4u& Vector4u::operator*=(const Vector4u& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;

    return *this;
}

Vector4u& Vector4u::operator*=(uint32 v)
{
    x *= v;
    y *= v;
    z *= v;
    w *= v;

    return *this;
}

Vector4u& Vector4u::operator/=(const Vector4u& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;

    return *this;
}

Vector4u& Vector4u::operator/=(uint32 v)
{
    x /= v;
    y /= v;
    z /= v;
    w /= v;

    return *this;
}

uint32& Vector4u::operator[](uint32 i)
{
    return (&x)[i];
}

Vector4u operator+(const Vector4u& lhs, const Vector4u& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
}

Vector4u operator-(const Vector4u& lhs, const Vector4u& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w };
}

Vector4u operator*(const Vector4u& lhs, const Vector4u& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w };
}

Vector4u operator*(const Vector4u& lhs, uint32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs };
}

Vector4u operator*(uint32 lhs, const Vector4u& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w };
}

Vector4u operator/(const Vector4u& lhs, const Vector4u& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w };
}

Vector4u operator/(const Vector4u& lhs, uint32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs };
}
} // namespace chill
