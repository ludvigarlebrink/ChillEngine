#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

#include <string>

namespace chill
{
/**
 * @brief A texture.
 */
class RENDER_CORE_API Texture
{
public:

    enum class Format
    {
        R,
        RG,
        RGB,
        RGBA
    };

public:

    /**
     * @brief Creates a texture.
     */
    Texture();

    /**
     * @brief Destroys a texture.
     */
    virtual ~Texture();

    void Create(int32 width, int32 height, Format format, void* pData);

    void CreateSubTexture(int32 xOffset, int32 yOffset, int32 width, int32 height, void* pData);

    Format GetFormat() const;

    int32 GetHeight() const;

    int32 GetWidth() const;
    
    bool LoadFromFile(const std::string& filename);

    void Bind(uint32 location);

private:

    void SetUp();

    void TearDown();

    uint32 ToGLFormat(Format format);

private:

    bool m_isInitialized;
    Format m_format;
    int32 m_height;
    int32 m_width;
    uint32 m_textureId;
};
} // namespace chill
