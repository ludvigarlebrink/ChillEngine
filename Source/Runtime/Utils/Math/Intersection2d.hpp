#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

namespace chill
{
struct Circlef;

/**
 * @brief A collection of intersection tests in 2d-space.
 */
class UTILS_API Intersection2d
{
public:

    /**
     * @brief Test if two circles intersects.
     *
     * @param c1 First circle to test.
     * @param c2 Second circle to test.
     * @return True the two circles intersects. False if not.
     */
    static bool test(const Circlef& c1, const Circlef& c2);
};
} // namespace chill

/**
 * @class chill::Intersection2d
 */
