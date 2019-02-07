#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
struct Vector3f;

/**
 * @brief A 3x3 matrix.
 */
struct UTILS_API Matrix3f
{
public:

    Matrix3f();

    Matrix3f(const Matrix3f& other);

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
    Matrix3f(f32 ax, f32 bx, f32 cx, f32 ay, f32 by, f32 cy,
        f32 az, f32 bz, f32 cz);

    Matrix3f(const Vector3f& row1, const Vector3f& row2, const Vector3f& row3);

    Matrix3f(f32 scale);

    void transpose();

    Matrix3f& operator=(const Matrix3f& other);

    f32* operator[](uint32 i);

public:

    f32 rows[3][3];
};
} // namespace chill
