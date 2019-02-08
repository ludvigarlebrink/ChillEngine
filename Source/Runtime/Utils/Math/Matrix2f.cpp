#include "Matrix2f.hpp"
#include "Vector2f.hpp"

namespace chill
{
const Matrix2f Matrix2f::IDENTITY = Matrix2f(1.0f);

Matrix2f::Matrix2f()
{
    m[0][0] = 0.0f;
    m[0][1] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 0.0f;
}

Matrix2f::Matrix2f(const Matrix2f& other)
{
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
}

Matrix2f::Matrix2f(f32 ax, f32 bx, f32 ay, f32 by)
{
    m[0][0] = ax;
    m[0][1] = ay;
    m[1][0] = bx;
    m[1][1] = by;
}

Matrix2f::Matrix2f(const Vector2f& col1, const Vector2f& col2)
{
    m[0][0] = col1.x;
    m[0][1] = col1.y;
    m[1][0] = col2.x;
    m[1][1] = col2.y;
}

Matrix2f::Matrix2f(f32 scale)
{
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = 1.0f;
}

void Matrix2f::transpose()
{
    Matrix2f mat(*this);

    m[0][1] = mat.m[1][0];
    m[1][0] = mat.m[0][1];
}

std::string Matrix2f::toString() const
{
    return "(" + std::to_string(m[0][0]) + ", " + std::to_string(m[1][0]) + ")\n" +
        "(" + std::to_string(m[0][1]) + ", " + std::to_string(m[1][1]) + ")";
}

Matrix2f& Matrix2f::operator=(const Matrix2f& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        m[0][0] = other.m[0][0];
        m[0][1] = other.m[0][1];

        m[1][0] = other.m[1][0];
        m[1][1] = other.m[1][1];
    }

    return *this;
}

Matrix2f& Matrix2f::operator*=(const Matrix2f& other)
{
    Matrix2f mat(*this);

    m[0][0] = mat.m[0][0] * other.m[0][0] + mat.m[0][1] * other.m[1][0];
    m[1][0] = mat.m[0][0] * other.m[0][1] + mat.m[0][1] * other.m[1][1];
    m[0][1] = mat.m[1][0] * other.m[0][0] + mat.m[1][1] * other.m[1][0];
    m[1][1] = mat.m[1][0] * other.m[0][1] + mat.m[1][1] * other.m[1][1];
    
    return *this;
}

f32* Matrix2f::operator[](uint32 i)
{
    return m[i];
}

Matrix2f operator*(const Matrix2f& lhs, const Matrix2f& rhs)
{
    Matrix2f mat(0.0f);

    mat[0][0] = lhs.m[0][0] * rhs.m[0][0] + lhs.m[0][1] * rhs.m[1][0];
    mat[1][0] = lhs.m[0][0] * rhs.m[0][1] + lhs.m[0][1] * rhs.m[1][1];
    mat[0][1] = lhs.m[1][0] * rhs.m[0][0] + lhs.m[1][1] * rhs.m[1][0];
    mat[1][1] = lhs.m[1][0] * rhs.m[0][1] + lhs.m[1][1] * rhs.m[1][1];

    return mat;
}
} // namespace chill
