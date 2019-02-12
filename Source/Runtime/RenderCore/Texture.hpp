#pragma once

#include "BaseTypes.hpp"

namespace chill
{
class Image;

/**
 * @brief A texture.
 */
class Texture
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

private:

    uint32 m_textureId;
};
} // namespace chill
