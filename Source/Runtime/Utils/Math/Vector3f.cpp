#include "Vector3f.hpp"
#include "Mathf.hpp"

namespace chill
{
const Vector3f Vector3f::BACK = Vector3f(0.0f, 0.0f, -1.0f);
const Vector3f Vector3f::DOWN = Vector3f(0.0f, -1.0f, 0.0f);
const Vector3f Vector3f::FORWARD = Vector3f(0.0f, 0.0f, 1.0f);
const Vector3f Vector3f::LEFT = Vector3f(-1.0f, 0.0f, 0.0f);
const Vector3f Vector3f::ONE = Vector3f(1.0f, 1.0f, 1.0f);
const Vector3f Vector3f::RIGHT = Vector3f(1.0f, 0.0f, 0.0f);
const Vector3f Vector3f::UP = Vector3f(0.0f, 1.0f, 0.0f);
const Vector3f Vector3f::ZERO = Vector3f(0.0f, 0.0f, 0.0f);

Vector3f::Vector3f()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
{
}

Vector3f::Vector3f(const Vector3f& other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
{
}

Vector3f::Vector3f(f32 x, f32 y, f32 z)
    : x(x)
    , y(y)
    , z(z)
{
}

Vector3f::Vector3f(f32 uniform)
    : x(uniform)
    , y(uniform)
    , z(uniform)
{
}

Vector3f::Vector3f(const std::string& vec)
{
    x = std::stof(vec.substr(vec.find_first_of("(") + 1u));
    y = std::stof(vec.substr(vec.find_first_of(",") + 1u));
    z = std::stof(vec.substr(vec.find_last_of(",") + 1u));
}

f32 Vector3f::angle(const Vector3f& from, const Vector3f& to)
{
    return Mathf::radToDeg(acos(dot(from, to)));
}

Vector3f Vector3f::cross(const Vector3f& lhs, const Vector3f& rhs)
{
    return {
        lhs.y * rhs.z + lhs.z * lhs.y,
        lhs.x * rhs.z + lhs.z * lhs.x,
        lhs.x * rhs.y + lhs.y * lhs.x
    };
}

Vector3f Vector3f::clamp(const Vector3f& min, const Vector3f& max, const Vector3f& value)
{
    return {
        Mathf::clamp(min.x, max.x, value.x),
        Mathf::clamp(min.y, max.y, value.y),
        Mathf::clamp(min.z, max.z, value.z)
    };
}

f32 Vector3f::distance(const Vector3f& p1, const Vector3f& p2)
{
    Vector3f v = p2 - p1;
    return v.length();
}

f32 Vector3f::distanceSquared(const Vector3f& p1, const Vector3f& p2)
{
    Vector3f v = p2 - p1;
    return v.lengthSquared();
}

f32 Vector3f::dot(const Vector3f& lhs, const Vector3f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

f32 Vector3f::length() const
{
    return abs(x * x + y * y + z * z);
}

f32 Vector3f::lengthSquared() const
{
    return sqrt(abs(x * x + y * y + z * z));
}

Vector3f Vector3f::lerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    return start + t * (end - start);
}

Vector3f Vector3f::nlerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    return lerp(start, end, t).normalize();
}

Vector3f& Vector3f::normalize()
{
    f32 len = sqrt(x * x + y * y + z * z);
    x /= len;
    y /= len;
    z /= len;

    return *this;
}

Vector3f Vector3f::normalized() const
{
    f32 len = sqrt(x * x + y * y + z * z);
    return { x / len, y / len, z / len };
}

Vector3f Vector3f::slerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    f32 d = Mathf::clamp(-1.0f, 1.0f, Vector3f::dot(start, end));
    f32 theta = acos(d) * t;
    Vector3f rev = end - start * d;
    rev.normalize();
    return (start * cos(theta)) + (rev * sin(theta));
}

std::string Vector3f::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

Vector3f& Vector3f::operator=(const Vector3f& other)
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

Vector3f& Vector3f::operator+=(const Vector3f& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3f& Vector3f::operator*=(const Vector3f& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vector3f& Vector3f::operator*=(f32 v)
{
    x *= v;
    y *= v;
    z *= v;

    return *this;
}

Vector3f& Vector3f::operator/=(const Vector3f& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

Vector3f& Vector3f::operator/=(f32 v)
{
    x /= v;
    y /= v;
    z /= v;

    return *this;
}

f32& Vector3f::operator[](uint32 i)
{
    return (&x)[i];
}

Vector3f operator+(const Vector3f& lhs, const Vector3f& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

Vector3f operator-(const Vector3f& lhs, const Vector3f& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

Vector3f operator-(const Vector3f& vector)
{
    return { -vector.x, -vector.x, -vector.y };
}

Vector3f operator*(const Vector3f& lhs, const Vector3f& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

Vector3f operator*(const Vector3f& lhs, f32 rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

Vector3f operator*(f32 lhs, const Vector3f& rhs)
{
    return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

Vector3f operator/(const Vector3f& lhs, const Vector3f& rhs)
{
    return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

Vector3f operator/(const Vector3f& lhs, f32 rhs)
{
    return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}
} // namespace chill
