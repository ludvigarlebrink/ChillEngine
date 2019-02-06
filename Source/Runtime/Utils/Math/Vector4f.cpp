#include "Vector4f.hpp"

namespace chill
{
Vector4f::Vector4f()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector4f& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(other.w)
{
}

Vector4f::Vector4f(f32 x, f32 y, f32 z, f32 w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector4f::Vector4f(uint32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
    , w(uniform)
{
}

Vector4f::Vector4f(const std::string& str)
{
}

std::string Vector4f::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}

Vector4f& Vector4f::operator=(const Vector4f& other)
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

Vector4f& Vector4f::operator+=(const Vector4f& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}

Vector4f& Vector4f::operator-=(const Vector4f& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}

Vector4f& Vector4f::operator*=(const Vector4f& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;

    return *this;
}

Vector4f& Vector4f::operator*=(f32 v)
{
    x *= v;
    y *= v;
    z *= v;
    w *= v;

    return *this;
}

Vector4f& Vector4f::operator/=(const Vector4f& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;

    return *this;
}

Vector4f& Vector4f::operator/=(f32 v)
{
    x /= v;
    y /= v;
    z /= v;
    w /= v;

    return *this;
}

f32& Vector4f::operator[](uint32 i)
{
    return (&x)[i];
}

Vector4f operator+(const Vector4f& lhs, const Vector4f& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
}

Vector4f operator-(const Vector4f& lhs, const Vector4f& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w };
}

Vector4f operator-(const Vector4f& vector)
{
    return { -vector.x, -vector.y, -vector.z, -vector.w };
}

Vector4f operator*(const Vector4f& lhs, const Vector4f& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w };
}

Vector4f operator*(const Vector4f& lhs, f32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs };
}

Vector4f operator*(f32 lhs, const Vector4f& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w };
}

Vector4f operator/(const Vector4f& lhs, const Vector4f& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w };
}

Vector4f operator/(const Vector4f& lhs, f32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs };
}
} // namespace chill
