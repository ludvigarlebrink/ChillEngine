#include "Color.hpp"

namespace chill
{
Color::Color()
    : r(255u)
    , g(255u)
    , b(255u)
    , a(255u)
{
}

Color::Color(const Color& other)
    : r(other.r)
    , g(other.g)
    , b(other.b)
    , a(other.a)
{
}

Color::Color(uint8 r, uint8 g, uint8 b, uint8 a)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
{
}

Color::Color(uint8 r, uint8 g, uint8 b)
    : r(r)
    , g(g)
    , b(b)
    , a(255u)
{
}

Color::Color(uint8 greyscale, uint8 a)
    : r(greyscale)
    , g(greyscale)
    , b(greyscale)
    , a(a)
{
}

Color::Color(uint8 greyscale)
    : r(greyscale)
    , g(greyscale)
    , b(greyscale)
    , a(255u)
{
}

Color& Color::operator=(const Color& other)
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
} // namespace chill
