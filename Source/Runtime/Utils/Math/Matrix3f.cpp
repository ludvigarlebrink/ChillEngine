#include "Matrix3f.hpp"
#include "Vector3f.hpp"

namespace chill
{
const Matrix3f Matrix3f::IDENTITY = Matrix3f(1.0f);

Matrix3f::Matrix3f()
{
    m[0][0] = 0.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = 0.0f;
    m[1][2] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 0.0f;
}

Matrix3f::Matrix3f(const Matrix3f& other)
{
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[0][2] = other.m[0][2];

    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
    m[1][2] = other.m[1][2];

    m[2][0] = other.m[2][0];
    m[2][1] = other.m[2][1];
    m[2][2] = other.m[2][2];
}

Matrix3f::Matrix3f(f32 ax, f32 bx, f32 cx, f32 ay, f32 by, f32 cy,
    f32 az, f32 bz, f32 cz)
{
    m[0][0] = ax;
    m[0][1] = ay;
    m[0][2] = az;

    m[1][0] = bx;
    m[1][1] = by;
    m[1][2] = bz;

    m[2][0] = cx;
    m[2][1] = cy;
    m[2][2] = cz;
}

Matrix3f::Matrix3f(const Vector3f& row1, const Vector3f& row2, const Vector3f& row3)
{
    m[0][0] = row1.x;
    m[0][1] = row1.y;
    m[0][2] = row1.z;

    m[1][0] = row2.x;
    m[1][1] = row2.y;
    m[1][2] = row2.z;

    m[2][0] = row3.x;
    m[2][1] = row3.y;
    m[2][2] = row3.z;
}

Matrix3f::Matrix3f(f32 scale)
{
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
}

std::string Matrix3f::toString() const
{
    return "(" + std::to_string(m[0][0]) + ", " + std::to_string(m[1][0]) + ", " + std::to_string(m[2][0]) + ")\n" +
        "(" + std::to_string(m[0][1]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[2][1]) + ")\n" +
        "(" + std::to_string(m[0][2]) + ", " + std::to_string(m[1][2]) + ", " + std::to_string(m[2][2]) + ")\n";
}

void Matrix3f::transpose()
{
    Matrix3f mat(*this);

    m[0][1] = mat.m[1][0];
    m[0][2] = mat.m[2][0];

    m[1][0] = mat.m[0][1];
    m[1][2] = mat.m[2][1];

    m[2][0] = mat.m[0][2];
    m[2][1] = mat.m[1][2];
}

Matrix3f& Matrix3f::operator=(const Matrix3f& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        m[0][0] = other.m[0][0];
        m[0][1] = other.m[0][1];
        m[0][2] = other.m[0][2];

        m[1][0] = other.m[1][0];
        m[1][1] = other.m[1][1];
        m[1][2] = other.m[1][2];

        m[2][0] = other.m[2][0];
        m[2][1] = other.m[2][1];
        m[2][2] = other.m[2][2];
    }

    return *this;
}

f32* Matrix3f::operator[](uint32 i)
{
    return m[i];
}
} // namespace chill
