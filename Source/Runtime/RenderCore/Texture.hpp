#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

#include <string>

namespace chill
{
class Image;

/**
 * @brief A texture.
 */
class RENDER_CORE_API Texture
{
public:

    /**
     * @brief Creates a texture.
     */
    Texture();

    /**
     * @brief Destroys a texture.
     */
    virtual ~Texture();
    
    bool LoadFromFile(const std::string& filename);

    void Bind(uint32 location);

private:

    void SetUp();

    void TearDown();

private:

    bool m_isInitialized;
    int32 m_components;
    int32 m_height;
    int32 m_width;
    uint32 m_textureId;
};
} // namespace chill
