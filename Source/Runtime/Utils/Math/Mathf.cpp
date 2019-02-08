#include "MathF.hpp"

namespace chill
{
const f32 PI = 3.14159265359f;

f32 Mathf::clamp(f32 min, f32 max, f32 value)
{
    if (value > max)
    {
        return max;
    }

    if (value < min)
    {
        return min;
    }

    return value;
}

f32 Mathf::degToRad(f32 deg)
{
    return deg * 0.0174532925f;
}

f32 Mathf::lerp(f32 start, f32 end, f32 t)
{
    return start + t * (end - start);
}

f32 Mathf::max(f32 a, f32 b)
{
    return a > b ? a : b;
}

f32 Mathf::min(f32 a, f32 b)
{
    return a < b ? a : b;
}

f32 Mathf::radToDeg(f32 rad)
{
    return rad * 57.2957795f;
}
} // namespace chill
