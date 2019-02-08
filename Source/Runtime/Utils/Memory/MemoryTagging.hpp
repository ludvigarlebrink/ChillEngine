/**
 * @file     MemoryTagging.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief memory tagging policies
 */

#pragma once


class NoMemoryTagging
{
public:
    inline void TagAllocation(void*, size_t) const {}
    inline void TagDeallocation(void*, size_t) const {}
};