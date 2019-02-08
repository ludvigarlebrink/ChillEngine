#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
struct AABounds2d;
struct Circle2d;

/**
 * @brief A collection of intersection tests in 2d-space.
 */
class UTILS_API Intersection2d
{
public:

    /**
     * @brief Test if two axis-aligned bounds intersects.
     *
     * @param a First axis-aligned bounds to test.
     * @param b Second axis-aligned bounds to test.
     * @return True the two axis-aligned bounds intersects. False if not.
     */
    static bool test(const AABounds2d& a, const AABounds2d& b);

    /**
     * @brief Test if two circles intersects.
     *
     * @param a First circle to test.
     * @param b Second circle to test.
     * @return True the two circles intersects. False if not.
     */
    static bool test(const Circle2d& a, const Circle2d& b);
};
} // namespace chill

/**
 * @class chill::Intersection2d
 * @ingroup Math
 */
