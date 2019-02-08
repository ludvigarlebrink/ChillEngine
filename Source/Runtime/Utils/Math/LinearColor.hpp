#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
/**
 * @brief A color (or colour for you english people) in linear space.
 */
struct UTILS_API LinearColor
{
public:

    /**
     * @brief Creates a color.
     */
    LinearColor();

    /**
     * @brief Copies a color.
     *
     * @param other Linear color to copy from.
     */
    LinearColor(const LinearColor& other);

    /**
     * @brief Creates a color.
     *
     * @param r Red component.
     * @param g Green component.
     * @param b Blue component.
     * @param a Alpha component.
     */
    LinearColor(f32 r, f32 g, f32 b, f32 a);

    /**
     * @brief Creates a color.
     *
     * @param r Red component.
     * @param g Green component.
     * @param b Blue component.
     */
    LinearColor(f32 r, f32 g, f32 b);

    /**
     * @brief Clamps all components between 0 and 1.
     */
    void clamp();

    LinearColor& operator=(const LinearColor& other);

    LinearColor& operator+=(const LinearColor& other);

    LinearColor& operator-=(const LinearColor& other);

    LinearColor& operator*=(const LinearColor& other);

    LinearColor& operator*=(f32 v);

    LinearColor& operator/=(const LinearColor& other);

    LinearColor& operator/=(f32 v);

    f32& operator[](uint32 i);

public:

    /**
     * @brief A very nice black color. Shorthand for LinearColor(0, 0, 0, 1).
     */
    static const LinearColor BLACK;

    /**
     * @brief A very nice blue color. Shorthand for LinearColor(0, 0, 1, 1).
     */
    static const LinearColor BLUE;

    /**
     * @brief A very nice green color. Shorthand for LinearColor(0, 1, 0, 1).
     */
    static const LinearColor GREEN;

    /**
     * @brief A very nice red color. Shorthand for LinearColor(1, 0, 0, 1).
     */
    static const LinearColor RED;

    /**
     * @brief A very nice white color. Shorthand for LinearColor(1, 1, 1, 1).
     */
    static const LinearColor WHITE;

    /**
     * @brief A very nice yellow color. Shorthand for LinearColor(1, 1, 0, 1).
     */
    static const LinearColor YELLOW;

    /**
     * @brief Red component.
     */
    f32 r;
    
    /**
     * @brief Green component.
     */
    f32 g;

    /**
     * @brief Blue component.
     */
    f32 b;

    /**
     * @brief Alpha component.
     */
    f32 a;
};
} // namespace chill

/**
 * @class chill::LinearColor
 * @ingroup Math
 */
