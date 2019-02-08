#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
/**
 * @brief A collection of mathematical functions.
 */
class UTILS_API  Mathf
{
public:

    /**
     * @brief Clamps a value between a minimum and a maximum float.
     *
     * @param min Minimum value.
     * @param max Maximum value.
     * @param value Float to be clamped.
     * @return Clamped float.
     */
    static f32 clamp(f32 min, f32 max, f32 value);

    /**
     * @brief Converts degrees to radians.
     *
     * @param deg Degrees as be converted.
     * @return Radians.
     */
    static f32 degToRad(f32 deg);

    /**
     * @param Linear interpolation between two floats.
     *
     * @param start Start value.
     * @param end End value.
     * @param t Interpolation value.
     * @return A linear interpolated value.
     */
    static f32 lerp(f32 start, f32 end, f32 t);

    /**
     * @brief Get the maximum of two floats.
     *
     * @param a First floats.
     * @param b Second floats.
     */
    static f32 max(f32 a, f32 b);

    /**
     * @brief Get the minimum of two floats.
     *
     * @param a First floats.
     * @param b Second floats.
     */
    static f32 min(f32 a, f32 b);

    /**
     * @brief Converts radians to degrees.
     *
     * @param rad Radians as be converted.
     * @return Degrees.
     */
    static f32 radToDeg(f32 rad);

public:

    /**
     * @brief A mathematical constant, shorthand for 3.14159265359.
     */
    static const f32 PI;
};
} // namespace chill

/**
 * @class chill::Mathf
 * @ingroup Math
 */
