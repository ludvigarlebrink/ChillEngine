#include "Vector2i.hpp"
#include "Vector2f.hpp"
#include "Vector2u.hpp"
#include "Vector3f.hpp"
#include "Vector3i.hpp"
#include "Vector3u.hpp"
#include "Vector4f.hpp"
#include "Vector4i.hpp"
#include "Vector4u.hpp"

namespace chill
{
const Vector2i Vector2i::DOWN = Vector2i(0, -1);
const Vector2i Vector2i::LEFT = Vector2i(-1, 0);
const Vector2i Vector2i::ONE = Vector2i(1, 1);
const Vector2i Vector2i::RIGHT = Vector2i(1, 0);
const Vector2i Vector2i::UP = Vector2i(0, 1);
const Vector2i Vector2i::ZERO = Vector2i(0, 0);

Vector2i::Vector2i()
    : x(0)
    , y(0)
{
}

Vector2i::Vector2i(const Vector2f& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(const Vector2i& other)
    : x(other.x)
    , y(other.y)
{
}

Vector2i::Vector2i(const Vector2u& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(const Vector3f& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(const Vector3i& other)
    : x(other.x)
    , y(other.y)
{
}

Vector2i::Vector2i(const Vector3u& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(const Vector4f& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(const Vector4i& other)
    : x(other.x)
    , y(other.y)
{
}

Vector2i::Vector2i(const Vector4u& other)
    : x(static_cast<int32>(other.x))
    , y(static_cast<int32>(other.y))
{
}

Vector2i::Vector2i(int32 x, int32 y)
    : x(x)
    , y(y)
{
}

Vector2i::Vector2i(int32 uniform)
    : x(uniform)
    , y(uniform)
{
}

Vector2i::Vector2i(const std::string& str)
{
    x = std::stoi(str.substr(str.find_first_of("(") + 1u));
    y = std::stoi(str.substr(str.find_first_of(",") + 1u));
}

std::string Vector2i::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2i& Vector2i::operator=(const Vector2i& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }

    return *this;
}

Vector2i& Vector2i::operator+=(const Vector2i& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2i& Vector2i::operator-=(const Vector2i& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2i& Vector2i::operator*=(const Vector2i& other)
{
    x *= other.x;
    y *= other.y;

    return *this;
}

Vector2i& Vector2i::operator*=(int32 v)
{
    x *= v;
    y *= v;

    return *this;
}

Vector2i& Vector2i::operator/=(const Vector2i& other)
{
    x /= other.x;
    y /= other.y;

    return *this;
}

Vector2i& Vector2i::operator/=(int32 v)
{
    x /= v;
    y /= v;

    return *this;
}

int32& Vector2i::operator[](uint32 i)
{
    return (&x)[i];
}

Vector2i operator+(const Vector2i& lhs, const Vector2i& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

Vector2i operator-(const Vector2i& lhs, const Vector2i& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Vector2i operator-(const Vector2i& vector)
{
    return { -vector.x, -vector.y };
}

Vector2i operator*(const Vector2i& lhs, const Vector2i& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y };
}

Vector2i operator*(const Vector2i& lhs, int32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs };
}

Vector2i operator*(int32 lhs, const Vector2i& rhs)
{
    return { lhs * rhs.y, lhs * rhs.y };
}

Vector2i operator/(const Vector2i& lhs, const Vector2i& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y };
}

Vector2i operator/(const Vector2i& lhs, int32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs };
}
} // namespace chill
