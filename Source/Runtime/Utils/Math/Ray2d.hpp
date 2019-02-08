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

    /**
     * @brief Creates a ray in 2d-space.
     */
    Ray2d();

    /**
     * @brief Copies a ray in 2d-space.
     *
     * @param other Ray to copy from.
     */
    Ray2d(const Ray2d& other);

    /**
     * @brief Creates a ray in 2d-space.
     *
     * @param origin Origin of the ray.
     * @param direction Direction of the ray (should be normalized).
     * @param tMax Maximum t value.
     */
    Ray2d(const Vector2f& origin, const Vector2f& direction, f32 tMax);

    /**
     * @brief Creates a ray in 2d-space.
     *
     * @param origin Origin of the ray.
     * @param direction Direction of the ray (should be normalized).
     */
    Ray2d(const Vector2f& origin, const Vector2f& direction);

    /**
     * @brief Creates a ray in 2d-space.
     *
     * @param xOrigin X component of the origin of the ray.
     * @param yOrigin y component of the origin of the ray.
     * @param xDir X component of the direction of the ray (should be normalized).
     * @param yDir Y component of the direction of the ray (should be normalized).
     * @param tMax Maximum t value.
     */
    Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir, f32 tMax);

    /**
     * @brief Creates a ray in 2d-space.
     *
     * @param xOrigin X component of the origin of the ray.
     * @param yOrigin y component of the origin of the ray.
     * @param xDir X component of the direction of the ray (should be normalized).
     * @param yDir Y component of the direction of the ray (should be normalized).
     */
    Ray2d(f32 xOrigin, f32 yOrigin, f32 xDir, f32 yDir);

    Ray2d operator=(const Ray2d& other);

public:

    /**
     * @brief Point of the ray origin.
     */
    Vector2f origin;

    /**
     * @brief Direction in which the ray will shoot.
     */
    Vector2f direction;

    /**
     * @brief Essentially the max length of the ray.
     */
    f32 tMax;
};
} // namespace chill

/**
 * @struct chill::Ray2d
 * @ingroup Math
 */
