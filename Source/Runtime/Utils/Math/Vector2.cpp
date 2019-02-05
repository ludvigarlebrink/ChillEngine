#include "Vector2.hpp"

namespace chill
{
const Vector2 Vector2::DOWN = Vector2(0.0f, -1.0f);
const Vector2 Vector2::LEFT = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::ONE = Vector2(1.0f, 1.0f);
const Vector2 Vector2::RIGHT = Vector2(1.0f, 0.0f);
const Vector2 Vector2::UP = Vector2(0.0f, 1.0f);
const Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);

Vector2::Vector2()
    : x(0.0f)
    , y(0.0f)
{
}

Vector2::Vector2(const Vector2& other)
    : x(other.x)
    , y(other.y)
{
}

Vector2::Vector2(f32 x, f32 y)
    : x(x)
    , y(y)
{
}

Vector2::Vector2(f32 uniform)
    : x(uniform)
    , y(uniform)
{
}

f32 Vector2::dot(const Vector2 & v1, const Vector2 & v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

void Vector2::normalize()
{
    f32 len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
}

f32 Vector2::length() const
{
    return x * x + y * y;
}

f32 Vector2::lengthSquared() const
{
    return sqrt(x * x + y * y);
}

std::string Vector2::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2& Vector2::operator=(const Vector2& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }

    return *this;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2& Vector2::operator*=(const Vector2& other)
{
    x *= other.x;
    y *= other.y;

    return *this;
}

Vector2& Vector2::operator/=(const Vector2& other)
{
    x /= other.x;
    y /= other.y;

    return *this;
}

f32& Vector2::operator[](uint32 i)
{
    return (&x)[i];
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Vector2 operator-(const Vector2& vector)
{
    return { -vector.x, -vector.y };
}

Vector2 operator*(const Vector2& lhs, const Vector2& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y };
}

Vector2 operator*(const Vector2& lhs, f32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs };
}

Vector2 operator*(f32 lhs, const Vector2& rhs)
{
    return { lhs * rhs.y, lhs * rhs.y };
}

Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y };
}

Vector2 operator/(const Vector2& lhs, f32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs };
}
} // namespace chill
