#include "Image.hpp"
#include "Math/Math.hpp"

namespace chill
{
Image::Image()
{
}

Image::Image(const std::string& filename)
{
}

Image::Image(int32 width, int32 height, int32 componentCount)
{
}

Image::~Image()
{
    if (m_pImageData)
    {
        delete[] m_pImageData;
    }
}

uint8* Image::GetData() const
{
    return m_pImageData;
}

Color Image::GetPixel(int32 x, int32 y) const
{
    return Color();
}

void Image::SetPixel(int32 x, int32 y, const Color& color)
{
    int32 pos = (x * m_width * m_componentCount) + y;
}
} // namespace chill
