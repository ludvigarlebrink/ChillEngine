#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
/**
 * @brief A collection of mathematical functions.
 */
class UTILS_API  MathF
{
public:

    /**
     * @brief Converts radians to degrees.
     *
     * @param rad Radians as be converted.
     * @return Degrees.
     */
    static f32 RadToDeg(f32 rad);

public:

    /**
     * @brief A mathematical constant, shorthand for 3.1415926f.
     */
    static const f32 PI;
};
} // namespace chill

/**
 * @class chill::MathF
 */