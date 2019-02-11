#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
struct Vector2i;

/**
 * @brief A simple rectangle.
 */
struct UTILS_API Recti
{
public:

    /**
     * @brief Creates a rectangle.
     */
    Recti();

    /**
     * @brief Copies a rectangle.
     *
     * @param other Rectangle to copy from.
     */
    Recti(const Recti& other);

    /**
     * @brief Creates a rectangle.
     *
     * @param x Position along the x-axis.
     * @param y Position along the y-axis.
     * @param w Width.
     * @param h Height.
     */
    Recti(int32 x, int32 y, int32 w, int32 h);

    /**
     * @brief Creates a rectangle from a string, format must be "(x, y, w, h)".
     *
     * @param vec String to create a rectangle from, format must be "(x, y, w, h)".
     */
    Recti(const std::string& str);

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
    bool Contains(const Vector2i& point);

    Recti& operator=(const Recti& other);

public:

    /**
     * @brief Position along the x-axis of this rectangle.
     */
    int32 x;

    /**
     * @brief Position along the y-axis of this rectangle.
     */
    int32 y;

    /**
     * @brief Width this rectangle.
     */
    int32 w;

    /**
     * @brief Height this rectangle.
     */
    int32 h;
};
} // namespace chill

/**
 * @struct chill::Recti
 * @ingroup Math
 */
