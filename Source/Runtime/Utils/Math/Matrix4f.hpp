#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
struct Vector4f;

/**
 * @brief A 4x4 matrix.
 */
struct UTILS_API Matrix4f
{
public:

    /**
     * @brief Creates a matrix.
     */
    Matrix4f();

    /**
     * @brief Copies a matrix.
     *
     * @param other Matrix to copy from.
     */
    Matrix4f(const Matrix4f& other);

    /**
     * @brief Creates a matrix.
     *
     * @param ax AX component.
     * @param bx BX component.
     * @param cx CX component.
     * @param dx DX component.
     * @param ay AY component.
     * @param by BY component.
     * @param cy CY component.
     * @param dy DY component.
     * @param az AZ component.
     * @param bz BZ component.
     * @param cz CZ component.
     * @param dz DZ component.
     * @param aw AW component.
     * @param bw BW component.
     * @param cw CW component.
     * @param dw DW component.
     *
     * Marix layout:
     * (ax, bx, cx, dx)
     * (ay, by, cy, dy)
     * (az, bz, cz, dz)
     * (aw, bw, cw, dw)
     */
    Matrix4f(f32 ax, f32 bx, f32 cx, f32 dx, 
        f32 ay, f32 by, f32 cy, f32 dy,
        f32 az, f32 bz, f32 cz, f32 dz, 
        f32 aw, f32 bw, f32 cw, f32 dw);

    /**
     * @brief Creates a matrix.
     *
     * @param col1 First column.
     * @param col2 Second column.
     * @param col3 Third column.
     * @param col4 Fourth column.
     */
    Matrix4f(const Vector4f& col1, const Vector4f& col2, const Vector4f& col3, const Vector4f& col4);

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
    Matrix4f(f32 scale);

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

    Matrix4f& operator=(const Matrix4f& other);

    f32* operator[](uint32 i);

public:

    /**
     * @brief Shorthand for Matrix2f(1.0f).
     */
    static const Matrix4f IDENTITY;

    /**
     * @brief Matrix data.
     */
    f32 m[4][4];
};
} // namespace chill

/**
 * @class chill::Matrix4f
 * @ingroup Math
 */
