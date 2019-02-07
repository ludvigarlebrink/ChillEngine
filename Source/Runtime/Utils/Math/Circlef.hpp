#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"
#include "Vector2f.hpp"

namespace chill
{
/**
 * @brief A circle in 2d-space.
 */
struct UTILS_API Circlef
{
public:

    /**
     * @brief Creates a circle.
     */
    Circlef();

    Circlef(const Circlef& other);

    Circlef(const Vector2f& origin, f32 radius);

    Circlef(f32 xOrigin, f32 yOrigin, f32 radius);

    Circlef& operator=(const Circlef& other);

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
