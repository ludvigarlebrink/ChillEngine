#include "LinearColor.hpp"
#include "Mathf.hpp"

namespace chill
{
const LinearColor LinearColor::BLACK = LinearColor(0.0f, 0.0f, 0.0f, 1.0f);
const LinearColor LinearColor::BLUE = LinearColor(0.0f, 0.0f, 1.0f, 1.0f);
const LinearColor LinearColor::GREEN = LinearColor(0.0f, 1.0f, 0.0f, 1.0f);
const LinearColor LinearColor::RED = LinearColor(1.0f, 0.0f, 0.0f, 1.0f);
const LinearColor LinearColor::WHITE = LinearColor(1.0f, 1.0f, 1.0f, 1.0f);
const LinearColor LinearColor::YELLOW = LinearColor(1.0f, 1.0f, 0.0f, 1.0f);

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

    return *this;
}

LinearColor& LinearColor::operator-=(const LinearColor& other)
{
    r -= other.r;
    g -= other.g;
    b -= other.b;
    a -= other.a;

    return *this;
}

LinearColor& LinearColor::operator*=(const LinearColor& other)
{
    r *= other.r;
    g *= other.g;
    b *= other.b;
    a *= other.a;

    return *this;
}

LinearColor& LinearColor::operator*=(f32 v)
{
    r *= v;
    g *= v;
    b *= v;
    a *= v;

    return *this;
}

LinearColor& LinearColor::operator/=(const LinearColor& other)
{
    r /= other.r;
    g /= other.g;
    b /= other.b;
    a /= other.a;

    return *this;
}

LinearColor& LinearColor::operator/=(f32 v)
{
    r /= v;
    g /= v;
    b /= v;
    a /= v;

    return *this;
}

f32& LinearColor::operator[](uint32 i)
{
    return (&r)[i];
}
} // namespace chill
