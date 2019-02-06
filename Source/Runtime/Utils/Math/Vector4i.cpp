#include "Vector4i.hpp"

namespace chill
{
Vector4i::Vector4i()
    : x(0)
    , y(0)
    , z(0)
    , w(0)
{
}

Vector4i::Vector4i(const Vector4i& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(other.w)
{
}

Vector4i::Vector4i(int32 x, int32 y, int32 z, int32 w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector4i::Vector4i(int32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
    , w(uniform)
{
}

Vector4i::Vector4i(const std::string& str)
{
}

std::string Vector4i::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}

Vector4i& Vector4i::operator=(const Vector4i& other)
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

Vector4i& Vector4i::operator+=(const Vector4i& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}

Vector4i& Vector4i::operator-=(const Vector4i& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}

Vector4i& Vector4i::operator*=(const Vector4i& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;

    return *this;
}

Vector4i& Vector4i::operator*=(int32 v)
{
    x *= v;
    y *= v;
    z *= v;
    w *= v;

    return *this;
}

Vector4i& Vector4i::operator/=(const Vector4i& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;

    return *this;
}

Vector4i& Vector4i::operator/=(int32 v)
{
    x /= v;
    y /= v;
    z /= v;
    w /= v;

    return *this;
}

int32& Vector4i::operator[](uint32 i)
{
    return (&x)[i];
}

Vector4i operator+(const Vector4i& lhs, const Vector4i& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
}

Vector4i operator-(const Vector4i& lhs, const Vector4i& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w };
}

Vector4i operator-(const Vector4i& vector)
{
    return { -vector.x, -vector.y, -vector.z, -vector.w };
}

Vector4i operator*(const Vector4i& lhs, const Vector4i& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w };
}

Vector4i operator*(const Vector4i& lhs, int32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs };
}

Vector4i operator*(int32 lhs, const Vector4i& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w };
}

Vector4i operator/(const Vector4i& lhs, const Vector4i& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w };
}

Vector4i operator/(const Vector4i& lhs, int32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs };
}
} // namespace chill
