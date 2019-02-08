/**
 * @file     BoundsChecking.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief Memory bounds checking policies
 */

#pragma once


class NoBoundsChecking
{
public:
    static const size_t SIZE_FRONT = 0;
    static const size_t SIZE_BACK = 0;

    inline void GuardFront(void*) const {}
    inline void GuardBack(void*) const {}

    inline void CheckFront(const void*) const {}
    inline void CheckBack(const void*) const {}
};