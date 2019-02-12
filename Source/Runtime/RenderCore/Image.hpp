#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Math/MathFwd.hpp"

#include <string>

namespace chill
{
class RENDER_CORE_API Image
{
public:

    /**
     * @brief Creates a texture.
     */
    Image();

    /**
     * @brief Loads an image from a file.
     *
     * @param filename Name and path of file to load.
     */
    Image(const std::string& filename);

    Image(int32 width, int32 height, int32 componentCount);

    virtual ~Image();

    uint8* GetData() const;

    Color GetPixel(int32 x, int32 y) const;

    void SetPixel(int32 x, int32 y, const Color& color);

private:

    uint8* m_pImageData;
    int32 m_width;
    int32 m_height;
    int32 m_componentCount;
};
} // namespace chill
