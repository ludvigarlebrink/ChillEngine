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
     */
    Color(const Color& other);

    /**
     * @brief Creates a color.
     */
    Color(uint8 r, uint8 g, uint8 b, uint8 a);

    /**
     * @brief Creates a color.
     */
    Color(uint8 r, uint8 g, uint8 b);

    /**
     * @brief Creates a color.
     */
    Color(uint8 greyscale, uint8 a);

    /**
     * @brief Creates a color.
     */
    Color(uint8 greyscale);

    Color& operator=(const Color& other);

public:

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