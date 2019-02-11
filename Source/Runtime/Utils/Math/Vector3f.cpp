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

Vector3f::Vector3f(const std::string& str)
{
    x = std::stof(str.substr(str.find_first_of("(") + 1u));
    y = std::stof(str.substr(str.find_first_of(",") + 1u));
    z = std::stof(str.substr(str.find_last_of(",") + 1u));
}

f32 Vector3f::Angle(const Vector3f& from, const Vector3f& to)
{
    return Mathf::RadToDeg(acos(Dot(from, to)));
}

Vector3f Vector3f::Cross(const Vector3f& lhs, const Vector3f& rhs)
{
    return {
        lhs.y * rhs.z + lhs.z * lhs.y,
        lhs.x * rhs.z + lhs.z * lhs.x,
        lhs.x * rhs.y + lhs.y * lhs.x
    };
}

void Vector3f::Clamp(const Vector3f& min, const Vector3f& max)
{
    x = Mathf::Clamp(min.x, max.x, x);
    y = Mathf::Clamp(min.y, max.y, y);
    z = Mathf::Clamp(min.z, max.z, z);
}

f32 Vector3f::Distance(const Vector3f& p1, const Vector3f& p2)
{
    Vector3f v = p2 - p1;
    return v.Length();
}

f32 Vector3f::DistanceSquared(const Vector3f& p1, const Vector3f& p2)
{
    Vector3f v = p2 - p1;
    return v.LengthSquared();
}

f32 Vector3f::Dot(const Vector3f& lhs, const Vector3f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

f32 Vector3f::Length() const
{
    return abs(x * x + y * y + z * z);
}

f32 Vector3f::LengthSquared() const
{
    return sqrt(abs(x * x + y * y + z * z));
}

Vector3f Vector3f::Lerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    return start + t * (end - start);
}

Vector3f Vector3f::Nlerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    return Lerp(start, end, t).Normalized();
}

void Vector3f::Normalize()
{
    f32 len = sqrt(x * x + y * y + z * z);
    x /= len;
    y /= len;
    z /= len;
}

Vector3f Vector3f::Normalized() const
{
    f32 len = sqrt(x * x + y * y + z * z);
    return { x / len, y / len, z / len };
}

Vector3f Vector3f::Slerp(const Vector3f& start, const Vector3f& end, f32 t)
{
    f32 d = Mathf::Clamp(-1.0f, 1.0f, Vector3f::Dot(start, end));
    f32 theta = acos(d) * t;
    Vector3f rev = end - start * d;
    rev.Normalize();
    return (start * cos(theta)) + (rev * sin(theta));
}

std::string Vector3f::ToString() const
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
