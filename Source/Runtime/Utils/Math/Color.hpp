#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
/**
 * @brief A RGBA color.
 */
struct UTILS_API Color
{
public:

    /**
     * @brief Creates a color.
     */
    Color();

    /**
     * @brief Copies a color.
     *
     * @param other Color to copy from.
     */
    Color(const Color& other);

    /**
     * @brief Creates a color.
     *
     * @param r Red component.
     * @param g Green component.
     * @param b Blue component.
     * @param a Alpha component.
     */
    Color(uint8 r, uint8 g, uint8 b, uint8 a);

    /**
     * @brief Creates a color.
     *
     * @param r Red component.
     * @param g Green component.
     * @param b Blue component.
     */
    Color(uint8 r, uint8 g, uint8 b);

    /**
     * @brief Creates a color.
     *
     * @param greyscale Greyscale.
     * @param a Alpha component.
     */
    Color(uint8 greyscale, uint8 a);

    /**
     * @brief Creates a color.
     *
     * @param greyscale Greyscale.
     */
    Color(uint8 greyscale);

    Color& operator=(const Color& other);

    uint8& operator[](uint32 i);

public:

    /**
     * @brief A very nice black color. Shorthand for LinearColor(0, 0, 0, 255).
     */
    static const Color BLACK;

    /**
     * @brief A very nice blue color. Shorthand for LinearColor(0, 0, 255, 255).
     */
    static const Color BLUE;

    /**
     * @brief A very nice green color. Shorthand for LinearColor(0, 255, 0, 255).
     */
    static const Color GREEN;

    /**
     * @brief A very nice red color. Shorthand for LinearColor(255, 0, 0, 255).
     */
    static const Color RED;

    /**
     * @brief A very nice white color. Shorthand for LinearColor(255, 255, 255, 255).
     */
    static const Color WHITE;

    /**
     * @brief A very nice yellow color. Shorthand for LinearColor(255, 255, 0, 255).
     */
    static const Color YELLOW;

    /**
     * @brief Red component.
     */
    uint8 r;

    /**
     * @brief Green component.
     */
    uint8 g;

    /**
     * @brief Blue component.
     */
    uint8 b;

    /**
     * @brief Alpha component.
     */
    uint8 a;
};
} // namespace chill

/**
 * @struct chill::Color
 * @ingroup Math
 */
