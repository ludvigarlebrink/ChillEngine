#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"
#include "Vector2f.hpp"

#include <string>

namespace chill
{
/**
 * @brief A ray in 2d-space.
 */
struct UTILS_API Ray2d
{
public:

    Ray2d();

    Ray2d(const Ray2d& other);

    Ray2d(const Vector2f& origin, const Vector2f& direction, f32 tMax);

    Ray2d(const Vector2f& origin, const Vector2f& direction);

    Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir, f32 tMax);

    Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir);

    Ray2d operator=(const Ray2d& other);

public:

    Vector2f origin;
    Vector2f direction;
    f32 tMax;
};
} // namespace chill

/**
 * @struct chill::Ray2d
 */
