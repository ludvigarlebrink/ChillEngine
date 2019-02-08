/**
 * @file     ThreadPolicy.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief thread locking policy
 */

#pragma once

class SingleThreadPolicy
{
public:
    inline void Enter(void) const {}
    inline void Leave(void) const {}
};

template <class SynchronizationPrimitive>
class MultiThreadPolicy
{
public:
    inline void Enter(void)
    {
        m_primitive.Enter();
    }

    inline void Leave(void)
    {
        m_primitive.Leave();
    }

private:
    SynchronizationPrimitive m_primitive;
};