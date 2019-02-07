#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
struct Vector2f;

/**
 * @brief A 2x2 matrix.
 */
struct UTILS_API Matrix2f
{
public:

    /**
     * @brief Creates a matrix.
     */
    Matrix2f();

    Matrix2f(const Matrix2f& other);

    /**
     * @brief Creates a matrix.
     *
     * @param ax
     * @param bx
     * @param ay
     * @param by
     *
     * (ax, bx)
     * (ay, by)
     */
    Matrix2f(f32 ax, f32 bx, f32 ay, f32 by);

    Matrix2f(const Vector2f& col1, const Vector2f& col2);

    Matrix2f(f32 scale);

    /**
     * @brief Transpose this matrix.
     */
    void transpose();

    Matrix2f& operator=(const Matrix2f& other);

    Matrix2f& operator*=(const Matrix2f& other);

    f32* operator[](uint32 i);

public:

    f32 m[2][2];
};

Matrix2f operator*(const Matrix2f& lhs, const Matrix2f& rhs);
} // namespace chill
