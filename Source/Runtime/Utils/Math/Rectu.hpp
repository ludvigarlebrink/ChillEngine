#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>

namespace chill
{
struct Vector2u;

/**
 * @brief A simple rectangle.
 */
struct UTILS_API Rectu
{
public:

    /**
     * @brief Creates a rectangle.
     */
    Rectu();

    /**
     * @brief Copies a rectangle.
     *
     * @param other Rectangle to copy from.
     */
    Rectu(const Rectu& other);

    /**
     * @brief Creates a rectangle.
     *
     * @param x Position along the x-axis.
     * @param y Position along the y-axis.
     * @param w Width.
     * @param h Height.
     */
    Rectu(uint32 x, uint32 y, uint32 w, uint32 h);

    /**
     * @brief Creates a rectangle from a string, format must be "(x, y, w, h)".
     *
     * @param vec String to create a rectangle from, format must be "(x, y, w, h)".
     */
    Rectu(const std::string& str);

    /**
     * @brief Get this rectangle as a nicely formated string: "(x, y, w, h)".
     *
     * @return A nicely formated string.
     */
    std::string toString() const;

    /**
     * @brief Test if this rectangle contains a point.
     *
     * @param point Point to be tested.
     * @return True if point is contained within this rectangle. False if not.
     */
    bool contains(const Vector2u& point);

    Rectu& operator=(const Rectu& other);

public:

    /**
     * @brief Position along the x-axis of this rectangle.
     */
    uint32 x;

    /**
     * @brief Position along the y-axis of this rectangle.
     */
    uint32 y;

    /**
     * @brief Width this rectangle.
     */
    uint32 w;

    /**
     * @brief Height this rectangle.
     */
    uint32 h;
};
} // namespace chill

/**
 * @struct chill::Rectu
 * @ingroup Math
 */
