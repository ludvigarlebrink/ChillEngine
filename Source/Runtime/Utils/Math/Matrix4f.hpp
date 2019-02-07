#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
struct Vector4f;

struct UTILS_API Matrix4f
{
public:

    Matrix4f();

    Matrix4f(const Matrix4f& other);

    Matrix4f(f32 ax, f32 ay, f32 az, f32 aw, f32 bx, f32 by, f32 bz, f32 bw,
        f32 cx, f32 cy, f32 cz, f32 cw, f32 dx, f32 dy, f32 dz, f32 dw);

    Matrix4f(const Vector4f& row1, const Vector4f& row2, const Vector4f& row3, const Vector4f& row4);

    Matrix4f(f32 scale);

    Matrix4f& operator=(const Matrix4f& other);

public:

    f32 rows[4][4];
};
} // namespace chill
