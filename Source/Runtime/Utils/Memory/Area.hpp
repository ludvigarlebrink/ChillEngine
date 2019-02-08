/**
 * @file     Area.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief areas
 */

#pragma once


class HeapArea
{
public:
    HeapArea(size_t size)
    {
        //mStart = (char*)malloc(size * sizeof(char));
        mEnd = mStart + size;
        mMemory = size;
    }
    ~HeapArea()
    {
        //free(mStart);
    }

    char* GetStart() { return mStart; }
    char* GetEnd() { return mEnd; }
    size_t GetMemory() { return mMemory; }

private:
    char* mStart;
    char* mEnd;
    size_t mMemory;
};

class StackArea {};