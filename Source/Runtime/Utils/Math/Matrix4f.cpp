#include "Matrix4f.hpp"
#include "Vector4f.hpp"

namespace chill
{
const Matrix4f Matrix4f::IDENTITY = Matrix4f(1.0f);

Matrix4f::Matrix4f()
{
    m[0][0] = 0.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = 0.0f;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 0.0f;
    m[2][3] = 0.0f;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 0.0f;
}

Matrix4f::Matrix4f(const Matrix4f& other)
{
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[0][2] = other.m[0][2];
    m[0][3] = other.m[0][3];

    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
    m[1][2] = other.m[1][2];
    m[1][3] = other.m[1][3];

    m[2][0] = other.m[2][0];
    m[2][1] = other.m[2][1];
    m[2][2] = other.m[2][2];
    m[2][3] = other.m[2][3];

    m[3][0] = other.m[3][0];
    m[3][1] = other.m[3][1];
    m[3][2] = other.m[3][2];
    m[3][3] = other.m[3][3];
}

Matrix4f::Matrix4f(f32 ax, f32 bx, f32 cx, f32 dx, f32 ay, f32 by, f32 cy, f32 dy,
    f32 az, f32 bz, f32 cz, f32 dz, f32 aw, f32 bw, f32 cw, f32 dw)
{
    m[0][0] = ax;
    m[0][1] = ay;
    m[0][2] = az;
    m[0][3] = aw;

    m[1][0] = bx;
    m[1][1] = by;
    m[1][2] = bz;
    m[1][3] = bw;

    m[2][0] = cx;
    m[2][1] = cy;
    m[2][2] = cz;
    m[2][3] = cw;

    m[3][0] = dx;
    m[3][1] = dy;
    m[3][2] = dz;
    m[3][3] = dw;
}

Matrix4f::Matrix4f(const Vector4f& col1, const Vector4f& col2, const Vector4f& col3, const Vector4f& col4)
{
    m[0][0] = col1.x;
    m[0][1] = col1.y;
    m[0][2] = col1.z;
    m[0][3] = col1.w;

    m[1][0] = col2.x;
    m[1][1] = col2.y;
    m[1][2] = col2.z;
    m[1][3] = col2.w;

    m[2][0] = col3.x;
    m[2][1] = col3.y;
    m[2][2] = col3.z;
    m[2][3] = col3.w;

    m[3][0] = col4.x;
    m[3][1] = col4.y;
    m[3][2] = col4.z;
    m[3][3] = col4.w;
}

Matrix4f::Matrix4f(f32 scale)
{
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
    m[2][3] = 0.0f;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

std::string Matrix4f::toString() const
{
    return "(" + std::to_string(m[0][0]) + ", " + std::to_string(m[1][0]) + ", " + std::to_string(m[2][0]) + ", " + std::to_string(m[3][0]) + ")\n"
        "(" + std::to_string(m[0][1]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[2][1]) + ", " + std::to_string(m[3][1]) + ")\n"
        "(" + std::to_string(m[0][2]) + ", " + std::to_string(m[1][2]) + ", " + std::to_string(m[2][2]) + ", " + std::to_string(m[3][2]) + ")\n"
        "(" + std::to_string(m[0][3]) + ", " + std::to_string(m[1][3]) + ", " + std::to_string(m[2][3]) + ", " + std::to_string(m[3][3]) + ")";
}

void Matrix4f::transpose()
{
    Matrix4f mat(*this);

    m[0][1] = mat.m[1][0];
    m[0][2] = mat.m[2][0];
    m[0][3] = mat.m[3][0];

    m[1][0] = mat.m[0][1];
    m[1][2] = mat.m[2][1];
    m[1][3] = mat.m[3][1];

    m[2][0] = mat.m[0][2];
    m[2][1] = mat.m[1][2];
    m[2][3] = mat.m[3][2];

    m[3][0] = mat.m[0][3];
    m[3][1] = mat.m[1][3];
    m[3][2] = mat.m[2][3];
}

Matrix4f& Matrix4f::operator=(const Matrix4f& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        m[0][0] = other.m[0][0];
        m[0][1] = other.m[0][1];
        m[0][2] = other.m[0][2];
        m[0][3] = other.m[0][3];

        m[1][0] = other.m[1][0];
        m[1][1] = other.m[1][1];
        m[1][2] = other.m[1][2];
        m[1][3] = other.m[1][3];

        m[2][0] = other.m[2][0];
        m[2][1] = other.m[2][1];
        m[2][2] = other.m[2][2];
        m[2][3] = other.m[2][3];

        m[3][0] = other.m[3][0];
        m[3][1] = other.m[3][1];
        m[3][2] = other.m[3][2];
        m[3][3] = other.m[3][3];
    }

    return *this;
}

f32* Matrix4f::operator[](uint32 i)
{
    return m[i];
}
} // namespace chill
