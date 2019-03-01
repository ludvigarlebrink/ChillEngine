#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
struct Vector2f;

/**
 * @brief A simple rectangle.
 */
struct UTILS_API Rectf
{
public:

    /**
     * @brief Creates a rectangle.
     */
    Rectf();

    /**
     * @brief Copies a rectangle.
     *
     * @param other Rectangle to copy from.
     */
    Rectf(const Rectf& other);

    /**
     * @brief Creates a rectangle.
     *
     * @param x Position along the x-axis.
     * @param y Position along the y-axis.
     * @param w Width.
     * @param h Height.
     */
    Rectf(f32 x, f32 y, f32 w, f32 h);

    /**
     * @brief Creates a rectangle from a string, format must be "(x, y, w, h)".
     *
     * @param vec String to create a rectangle from, format must be "(x, y, w, h)".
     */
    Rectf(const std::string& str);

    /**
     * @brief Get this rectangle as a nicely formated string: "(x, y, w, h)".
     *
     * @return A nicely formated string.
     */
    std::string ToString() const;

    /**
     * @brief Test if this rectangle contains a point.
     *
     * @param point Point to be tested.
     * @return True if point is contained within this rectangle. False if not.
     */
    bool Contains(const Vector2f& point);

    Rectf& operator=(const Rectf& other);

public:

    /**
     * @brief Position along the x-axis of this rectangle.
     */
    f32 x;

    /**
     * @brief Position along the y-axis of this rectangle.
     */
    f32 y;

    /**
     * @brief Width this rectangle.
     */
    f32 w;

    /**
     * @brief Height this rectangle.
     */
    f32 h;
};
} // namespace chill

/**
 * @struct chill::Rectf
 * @ingroup Math
 */
