#include "Matrix4f.hpp"
#include "Vector4f.hpp"

namespace chill
{
Matrix4f::Matrix4f()
{
    rows[0][0] = 0.0f;
    rows[0][1] = 0.0f;
    rows[0][2] = 0.0f;
    rows[0][3] = 0.0f;

    rows[1][0] = 0.0f;
    rows[1][1] = 0.0f;
    rows[1][2] = 0.0f;
    rows[1][3] = 0.0f;

    rows[2][0] = 0.0f;
    rows[2][1] = 0.0f;
    rows[2][2] = 0.0f;
    rows[2][3] = 0.0f;

    rows[3][0] = 0.0f;
    rows[3][1] = 0.0f;
    rows[3][2] = 0.0f;
    rows[3][3] = 0.0f;
}

Matrix4f::Matrix4f(const Matrix4f& other)
{
    rows[0][0] = other.rows[0][0];
    rows[0][1] = other.rows[0][1];
    rows[0][2] = other.rows[0][2];
    rows[0][3] = other.rows[0][3];

    rows[1][0] = other.rows[1][0];
    rows[1][1] = other.rows[1][1];
    rows[1][2] = other.rows[1][2];
    rows[1][3] = other.rows[1][3];

    rows[2][0] = other.rows[2][0];
    rows[2][1] = other.rows[2][1];
    rows[2][2] = other.rows[2][2];
    rows[2][3] = other.rows[2][3];

    rows[3][0] = other.rows[3][0];
    rows[3][1] = other.rows[3][1];
    rows[3][2] = other.rows[3][2];
    rows[3][3] = other.rows[3][3];
}

Matrix4f::Matrix4f(f32 ax, f32 bx, f32 cx, f32 dx, f32 ay, f32 by, f32 cy, f32 dy,
    f32 az, f32 bz, f32 cz, f32 dz, f32 aw, f32 bw, f32 cw, f32 dw)
{
    rows[0][0] = ax;
    rows[0][1] = ay;
    rows[0][2] = az;
    rows[0][3] = aw;

    rows[1][0] = bx;
    rows[1][1] = by;
    rows[1][2] = bz;
    rows[1][3] = bw;

    rows[2][0] = cx;
    rows[2][1] = cy;
    rows[2][2] = cz;
    rows[2][3] = cw;

    rows[3][0] = dx;
    rows[3][1] = dy;
    rows[3][2] = dz;
    rows[3][3] = dw;
}

Matrix4f::Matrix4f(const Vector4f& col1, const Vector4f& col2, const Vector4f& col3, const Vector4f& col4)
{
    rows[0][0] = col1.x;
    rows[0][1] = col1.y;
    rows[0][2] = col1.z;
    rows[0][3] = col1.w;

    rows[1][0] = col2.x;
    rows[1][1] = col2.y;
    rows[1][2] = col2.z;
    rows[1][3] = col2.w;

    rows[2][0] = col3.x;
    rows[2][1] = col3.y;
    rows[2][2] = col3.z;
    rows[2][3] = col3.w;

    rows[3][0] = col4.x;
    rows[3][1] = col4.y;
    rows[3][2] = col4.z;
    rows[3][3] = col4.w;
}

Matrix4f::Matrix4f(f32 scale)
{
    rows[0][0] = 1.0f;
    rows[0][1] = 0.0f;
    rows[0][2] = 0.0f;
    rows[0][3] = 0.0f;

    rows[1][0] = 0.0f;
    rows[1][1] = 1.0f;
    rows[1][2] = 0.0f;
    rows[1][3] = 0.0f;

    rows[2][0] = 0.0f;
    rows[2][1] = 0.0f;
    rows[2][2] = 1.0f;
    rows[2][3] = 0.0f;

    rows[3][0] = 0.0f;
    rows[3][1] = 0.0f;
    rows[3][2] = 0.0f;
    rows[3][3] = 1.0f;
}

Matrix4f& Matrix4f::operator=(const Matrix4f& m)
{
    // Check for self assignemnt.
    if (this != &m)
    {
        rows[0][0] = m.rows[0][0];
        rows[0][1] = m.rows[0][1];
        rows[0][2] = m.rows[0][2];
        rows[0][3] = m.rows[0][3];

        rows[1][0] = m.rows[1][0];
        rows[1][1] = m.rows[1][1];
        rows[1][2] = m.rows[1][2];
        rows[1][3] = m.rows[1][3];

        rows[2][0] = m.rows[2][0];
        rows[2][1] = m.rows[2][1];
        rows[2][2] = m.rows[2][2];
        rows[2][3] = m.rows[2][3];

        rows[3][0] = m.rows[3][0];
        rows[3][1] = m.rows[3][1];
        rows[3][2] = m.rows[3][2];
        rows[3][3] = m.rows[3][3];
    }

    return *this;
}

f32* Matrix4f::operator[](uint32 i)
{
    return rows[i];
}
} // namespace chill
