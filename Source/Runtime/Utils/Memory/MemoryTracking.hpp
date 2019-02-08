/**
 * @file     MemoryTracking.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief Memory bounds checking policies
 */

#pragma once

class NoMemoryTracking
{
public:
    //inline void OnAllocation(void*, size_t, size_t, const SourceInfo&) const {}
    inline void OnDeallocation(void*) const {}
};