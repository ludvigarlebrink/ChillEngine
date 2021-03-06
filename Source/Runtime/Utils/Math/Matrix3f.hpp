#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
struct Vector3f;

/**
 * @brief A 3x3 matrix.
 */
struct UTILS_API Matrix3f
{
public:

    /**
     * @brief Creates a matrix.
     */
    Matrix3f();

    /**
     * @brief Copies a matrix.
     *
     * @param other Matrix to copy from.
     */
    Matrix3f(const Matrix3f& other);

    /**
     * @brief Creates a matrix.
     *
     * @param ax AX component.
     * @param bx BX component.
     * @param ay AY component.
     * @param by 
     *
     * Matrix layout:
     * (ax, bx, cx)
     * (ay, by, cy)
     * (az, bz, cz)
     */
    Matrix3f(f32 ax, f32 bx, f32 cx,
        f32 ay, f32 by, f32 cy,
        f32 az, f32 bz, f32 cz);

    /**
     * @brief Creates a matrix.
     *
     * @param col1 First column.
     * @param col2 Second column.
     * @param col3 Third column.
     */
    Matrix3f(const Vector3f& col1, const Vector3f& col2, const Vector3f& col3);

    /**
     * @brief Creates a matrix.
     *
     * @param scale Scaling of the matrix.
     *
     * @code
     * // Identity matrix.
     * Matrix3f identity(1.0f);
     * @endcode
     */
    Matrix3f(f32 scale);

    /**
     * @brief Get this matrix as a nicely formated string.
     *
     * @return Matrix as a nicely formated string.
     */
    std::string ToString() const;

    /**
     * @brief Transpose this matrix.
     */
    void transpose();

    Matrix3f& operator=(const Matrix3f& other);

    f32* operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Matrix2f(1.0f).
     */
    static const Matrix3f IDENTITY;

    /**
     * @brief Matrix data.
     */
    f32 m[3][3];
};
} // namespace chill

/**
 * @class chill::Matrix3f
 * @ingroup Math
 */
