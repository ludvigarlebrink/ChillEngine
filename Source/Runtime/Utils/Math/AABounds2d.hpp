#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"
#include "Vector2f.hpp"

namespace chill
{
/**
 * @brief Defintion for axis-aligned bounds in 2d-space.
 */
struct UTILS_API AABounds2d
{
public:

    /**
     * @brief Creates axis-aligned bounds.
     */
    AABounds2d();

    AABounds2d(const AABounds2d& other);

    /**
     * @brief Creates axis-aligned bounds.
     */
    AABounds2d(const Vector2f& max, const Vector2f& min);

    AABounds2d& operator=(const AABounds2d& other);

public:

    Vector2f max;

    Vector2f min;
};
} // namespace chill

/**
 * @struct chill::AABounds2d
 */
