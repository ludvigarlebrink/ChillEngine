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

    /**
     * @brief Copies a matrix.
     *
     * @param other Matrix to copy from.
     */
    Matrix2f(const Matrix2f& other);

    /**
     * @brief Creates a matrix.
     *
     * @param ax AX component.
     * @param bx BX component.
     * @param ay AY component.
     * @param by BY component.
     *
     * Matrix layout:
     * (ax, bx)
     * (ay, by)
     */
    Matrix2f(f32 ax, f32 bx, f32 ay, f32 by);

    /**
     * @brief Creates a matrix.
     *
     * @param col1 First column.
     * @param col2 Second column.
     */
    Matrix2f(const Vector2f& col1, const Vector2f& col2);

    /**
     * @brief Creates a matrix.
     * 
     * @param scale Scaling of the matrix.
     *
     * @code
     * // Identity matrix.
     * Matrix2f identity(1.0f);
     * @endcode
     */
    Matrix2f(f32 scale);

    /**
     * @brief Transpose this matrix.
     */
    void transpose();

    Matrix2f& operator=(const Matrix2f& other);

    Matrix2f& operator*=(const Matrix2f& other);

    f32* operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Matrix2f(1.0f).
     */
    static const Matrix2f IDENTITY;

    /**
     * @brief Matrix data.
     */
    f32 m[2][2];
};

Matrix2f operator*(const Matrix2f& lhs, const Matrix2f& rhs);
} // namespace chill

/**
 * @class chill::Matrix2f
 * @ingroup Math
 */
