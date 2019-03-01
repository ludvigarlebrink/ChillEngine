#include "Vector4f.hpp"
#include "Vector2f.hpp"
#include "Vector2i.hpp"
#include "Vector2u.hpp"
#include "Vector3f.hpp"
#include "Vector3i.hpp"
#include "Vector3u.hpp"
#include "Vector4i.hpp"
#include "Vector4u.hpp"

namespace chill
{
Vector4f::Vector4f()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2f& other)
    : x(other.x)
    , y(other.y)
    , z(0.0f)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2f& other, f32 z)
    : x(other.x)
    , y(other.y)
    , z(z)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2f& other, f32 z, f32 w)
    : x(other.x)
    , y(other.y)
    , z(z)
    , w(w)
{
}

Vector4f::Vector4f(const Vector2i& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(0.0f)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2i& other, f32 z)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(z)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2i& other, f32 z, f32 w)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(z)
    , w(w)
{
}

Vector4f::Vector4f(const Vector2u& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(0.0f)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2u& other, f32 z)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(z)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector2u& other, f32 z, f32 w)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(z)
    , w(w)
{
}

Vector4f::Vector4f(const Vector3f& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector3f& other, f32 w)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(w)
{
}

Vector4f::Vector4f(const Vector3i& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector3i& other, f32 w)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(w)
{
}

Vector4f::Vector4f(const Vector3u& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(0.0f)
{
}

Vector4f::Vector4f(const Vector3u& other, f32 w)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(w)
{
}

Vector4f::Vector4f(const Vector4f& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    , w(other.w)
{
}

Vector4f::Vector4f(const Vector4i& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(static_cast<f32>(other.w))
{
}

Vector4f::Vector4f(const Vector4u& other)
    : x(static_cast<f32>(other.x))
    , y(static_cast<f32>(other.y))
    , z(static_cast<f32>(other.z))
    , w(static_cast<f32>(other.w))
{
}

Vector4f::Vector4f(f32 x, f32 y, f32 z, f32 w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector4f::Vector4f(f32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
    , w(uniform)
{
}

Vector4f::Vector4f(const std::string& str)
{
}

std::string Vector4f::ToString() const
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
