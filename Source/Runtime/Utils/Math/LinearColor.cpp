#include "LinearColor.hpp"
#include "Mathf.hpp"

namespace chill
{
LinearColor::LinearColor()
    : r(1.0f)
    , g(1.0f)
    , b(1.0f)
    , a(1.0f)
{
}

LinearColor::LinearColor(const LinearColor& other)
    : r(other.r)
    , g(other.g)
    , b(other.b)
    , a(other.a)
{
}

LinearColor::LinearColor(f32 r, f32 g, f32 b, f32 a)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
{
}

LinearColor::LinearColor(f32 r, f32 g, f32 b)
    : r(r)
    , g(g)
    , b(b)
    , a(1.0f)
{
}

void LinearColor::clamp()
{
    r = Mathf::clamp(0.0f, 1.0f, r);
    g = Mathf::clamp(0.0f, 1.0f, g);
    b = Mathf::clamp(0.0f, 1.0f, b);
    a = Mathf::clamp(0.0f, 1.0f, a);
}

LinearColor& LinearColor::operator=(const LinearColor& other)
{
    // Check for self assignemnt.
    if (this != &other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
    }

    return *this;
}

LinearColor& LinearColor::operator+=(const LinearColor& other)
{
    r += other.r;
    g += other.g;
    b += other.b;
    a += other.a;
}

LinearColor& LinearColor::operator-=(const LinearColor& other)
{
    r -= other.r;
    g -= other.g;
    b -= other.b;
    a -= other.a;
}

LinearColor& LinearColor::operator*=(const LinearColor& other)
{
    r *= other.r;
    g *= other.g;
    b *= other.b;
    a *= other.a;
}

LinearColor& LinearColor::operator*=(f32 v)
{
    r *= v;
    g *= v;
    b *= v;
    a *= v;
}

LinearColor& LinearColor::operator/=(const LinearColor& other)
{
    r /= other.r;
    g /= other.g;
    b /= other.b;
    a /= other.a;
}

LinearColor& LinearColor::operator/=(f32 v)
{
    r /= v;
    g /= v;
    b /= v;
    a /= v;
}

f32& LinearColor::operator[](uint32 i)
{
    // TODO: insert return statement here
}
} // namespace chill
