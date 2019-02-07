#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"
#include "Vector2f.hpp"

namespace chill
{
/**
 * @brief A circle in 2d-space.
 */
struct UTILS_API Circle2d
{
public:

    /**
     * @brief Creates a circle.
     */
    Circle2d();

    Circle2d(const Circle2d& other);

    Circle2d(const Vector2f& origin, f32 radius);

    Circle2d(f32 xOrigin, f32 yOrigin, f32 radius);

    Circle2d& operator=(const Circle2d& other);

public:

    /**
     * @brief Origin of the circle in 2d-space.
     */
    Vector2f origin;

    /**
     * @brief Radius of the circle.
     */
    f32 radius;
};
} // namespace chill

/**
 * @struct chill::Circlef
 */
