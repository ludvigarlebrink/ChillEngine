#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

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

    Matrix4f(const Matrix4f& other);

    /**
     * @brief Creates a matrix.
     *
     * @param ax
     * @param bx
     * @param ay
     * @param by
     *
     * (ax, bx, cx, dx)
     * (ay, by, cy, dy)
     * (az, bz, cz, dz)
     * (aw, bw, cw, dw)
     */
    Matrix4f(f32 ax, f32 bx, f32 cx, f32 dx, f32 ay, f32 by, f32 cy, f32 dy,
        f32 az, f32 bz, f32 cz, f32 dz, f32 aw, f32 bw, f32 cw, f32 dw);

    Matrix4f(const Vector4f& col1, const Vector4f& col2, const Vector4f& col3, const Vector4f& col4);

    Matrix4f(f32 scale);

    Matrix4f& operator=(const Matrix4f& other);

    f32* operator[](uint32 i);

public:

    f32 rows[4][4];
};
} // namespace chill
