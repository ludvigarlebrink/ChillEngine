/**
 * @file     MemoryManager.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief Manager responsible for object creation/deletion
 */

#pragma once

#define CHILL_NEW(type, arena)    new (arena.Allocate(sizeof(type), __FILE__, __LINE__)) type
#define CHILL_DELETE(object, arena)    ChillDelete(object, arena)
#define CHILL_NEW_ARRAY(type, arena)    NewChillArray<TypeAndCount<type>::Type>(arena, TypeAndCount<type>::Count, __FILE__, __LINE__, IntToType<IsPOD<TypeAndCount<type>::Type>::Value>())
#define CHILL_DELETE_ARRAY(object, arena)    DeleteChillArray(object, arena)

template <typename T, typename ARENA>
void ChillDelete(T* object, ARENA arena)
{
    // call the destructor first...
    object->~T();

    // ...and free the associated memory
    arena.Free(object);
}

template <class T>
struct TypeAndCount
{
};

template <class T, size_t N>
struct TypeAndCount<T[N]>
{
    typedef T Type;
    static const size_t Count = N;
};

template <typename T>
struct IsPOD
{
    static const bool Value = std::is_pod<T>::value;
};

template <bool I>
struct IntToType
{
};

typedef IntToType<false> NonPODType;
typedef IntToType<true> PODType;

template <typename T>
T* NewChillArray(size_t N, const char* file, int line, NonPODType)
{
    union
    {
        void* as_void;
        size_t* as_size_t;
        T* as_T;
    };

    as_void = m_arena.Allocate(sizeof(T)*N + sizeof(size_t), file, line);

    // store number of instances in first size_t bytes
    *as_size_t++ = N;

    // construct instances using placement new
    const T* const onePastLast = as_T + N;
    while (as_T < onePastLast)
        new (as_T++) T;

    // hand user the pointer to the first instance
    return (as_T - N);
}

template <typename T>
T* NewChillArray(size_t N, const char* file, int line, PODType)
{
    return static_cast(arena.Allocate(sizeof(T)*N, file, line));
}

template <typename T, class ARENA>
void DeleteArray(T* ptr, ARENA& arena)
{
    DeleteArray(ptr, arena, IntToType<IsPOD<T>::Value>());
}

template <typename T, class ARENA>
void DeleteChillArray(T* ptr, ARENA& arena, NonPODType)
{
    union
    {
        size_t* as_size_t;
        T* as_T;
    };

    // user pointer points to first instance...
    as_T = ptr;

    // ...so go back size_t bytes and grab number of instances
    const size_t N = as_size_t[-1];

    // call instances' destructor in reverse order
    for (size_t i = N; i > 0; --i)
        as_T[i - 1].~T();

    arena.Free(as_size_t - 1);
}

template <typename T, class ARENA>
void DeleteChillArray(T* ptr, ARENA& arena, PODType)
{
    arena.Free(ptr);
}
