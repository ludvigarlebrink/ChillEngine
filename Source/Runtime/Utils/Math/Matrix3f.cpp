#include "Matrix3f.hpp"
#include "Vector3f.hpp"

namespace chill
{
Matrix3f::Matrix3f()
{
    rows[0][0] = 0.0f;
    rows[0][1] = 0.0f;
    rows[0][2] = 0.0f;

    rows[1][0] = 0.0f;
    rows[1][1] = 0.0f;
    rows[1][2] = 0.0f;

    rows[2][0] = 0.0f;
    rows[2][1] = 0.0f;
    rows[2][2] = 0.0f;
}

Matrix3f::Matrix3f(const Matrix3f& other)
{
    rows[0][0] = other.rows[0][0];
    rows[0][1] = other.rows[0][1];
    rows[0][2] = other.rows[0][2];

    rows[1][0] = other.rows[1][0];
    rows[1][1] = other.rows[1][1];
    rows[1][2] = other.rows[1][2];

    rows[2][0] = other.rows[2][0];
    rows[2][1] = other.rows[2][1];
    rows[2][2] = other.rows[2][2];
}

Matrix3f::Matrix3f(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz,
    f32 cx, f32 cy, f32 cz)
{
    rows[0][0] = ax;
    rows[0][1] = ay;
    rows[0][2] = az;

    rows[1][0] = bx;
    rows[1][1] = by;
    rows[1][2] = bz;

    rows[2][0] = cx;
    rows[2][1] = cy;
    rows[2][2] = cz;
}

Matrix3f::Matrix3f(const Vector3f& row1, const Vector3f& row2, const Vector3f& row3)
{
    rows[0][0] = row1.x;
    rows[0][1] = row1.y;
    rows[0][2] = row1.z;

    rows[1][0] = row2.x;
    rows[1][1] = row2.y;
    rows[1][2] = row2.z;

    rows[2][0] = row3.x;
    rows[2][1] = row3.y;
    rows[2][2] = row3.z;
}

Matrix3f::Matrix3f(f32 scale)
{
    rows[0][0] = 1.0f;
    rows[0][1] = 0.0f;
    rows[0][2] = 0.0f;

    rows[1][0] = 0.0f;
    rows[1][1] = 1.0f;
    rows[1][2] = 0.0f;

    rows[2][0] = 0.0f;
    rows[2][1] = 0.0f;
    rows[2][2] = 1.0f;
}

void Matrix3f::transpose()
{
    Matrix3f m(*this);

    rows[0][1] = m.rows[1][0];
    rows[0][2] = m.rows[2][0];

    rows[1][0] = m.rows[0][1];
    rows[1][2] = m.rows[2][1];

    rows[2][0] = m.rows[0][2];
    rows[2][1] = m.rows[1][2];
}

Matrix3f& Matrix3f::operator=(const Matrix3f& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        rows[0][0] = other.rows[0][0];
        rows[0][1] = other.rows[0][1];
        rows[0][2] = other.rows[0][2];

        rows[1][0] = other.rows[1][0];
        rows[1][1] = other.rows[1][1];
        rows[1][2] = other.rows[1][2];

        rows[2][0] = other.rows[2][0];
        rows[2][1] = other.rows[2][1];
        rows[2][2] = other.rows[2][2];
    }

    return *this;
}

f32* Matrix3f::operator[](uint32 i)
{
    return rows[i];
}
} // namespace chill
