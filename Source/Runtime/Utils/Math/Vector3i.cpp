#include "Vector3i.hpp"

namespace chill
{
const Vector3i Vector3i::BACK = Vector3i(0, 0, -1);
const Vector3i Vector3i::DOWN = Vector3i(0, -1, 0);
const Vector3i Vector3i::FORWARD = Vector3i(0, 0, 1);
const Vector3i Vector3i::LEFT = Vector3i(-1, 0, 0);
const Vector3i Vector3i::ONE = Vector3i(1, 1, 1);
const Vector3i Vector3i::RIGHT = Vector3i(1, 0, 0);
const Vector3i Vector3i::UP = Vector3i(0, 1, 0);
const Vector3i Vector3i::ZERO = Vector3i(0, 0, 0);

Vector3i::Vector3i()
    : x(0)
    , y(0)
    , z(0)
{
}

Vector3i::Vector3i(const Vector3i& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
{
}

Vector3i::Vector3i(int32 x, int32 y, int32 z)
    : x(x)
    , y(y)
    , z(z)
{
}

Vector3i::Vector3i(int32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
{
}

Vector3i::Vector3i(const std::string& str)
{
    x = std::stoi(str.substr(str.find_first_of("(") + 1u));
    y = std::stoi(str.substr(str.find_first_of(",") + 1u));
    z = std::stoi(str.substr(str.find_last_of(",") + 1u));
}

std::string Vector3i::ToString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

Vector3i& Vector3i::operator=(const Vector3i& other)
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

Vector3i& Vector3i::operator+=(const Vector3i& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3i& Vector3i::operator-=(const Vector3i& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3i& Vector3i::operator*=(const Vector3i& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vector3i& Vector3i::operator*=(int32 v)
{
    x *= v;
    y *= v;
    z *= v;

    return *this;
}

Vector3i& Vector3i::operator/=(const Vector3i& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

Vector3i& Vector3i::operator/=(int32 v)
{
    x /= v;
    y /= v;
    z /= v;

    return *this;
}

int32& Vector3i::operator[](uint32 i)
{
    return (&x)[i];
}

Vector3i operator+(const Vector3i& lhs, const Vector3i& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

Vector3i operator-(const Vector3i& lhs, const Vector3i& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

Vector3i operator-(const Vector3i& vector)
{
    return { -vector.x, -vector.y, -vector.z };
}

Vector3i operator*(const Vector3i& lhs, const Vector3i& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

Vector3i operator*(const Vector3i& lhs, int32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

Vector3i operator*(int32 lhs, const Vector3i& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

Vector3i operator/(const Vector3i& lhs, const Vector3i& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

Vector3i operator/(const Vector3i& lhs, int32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}
} // namespace chill
