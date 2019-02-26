#include "Texture.hpp"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace chill
{
Texture::Texture()
    : m_isInitialized(false)
    , m_components(0)
    , m_height(0)
    , m_width(0)
    , m_textureId(0u)
{
}

Texture::~Texture()
{
    TearDown();
}

bool Texture::LoadFromFile(const std::string& filename)
{
    uint8* data = stbi_load(filename.c_str(), &m_width, &m_height, &m_components, STBI_rgb_alpha);
    if (!data)
    {
        return false;
    }

    SetUp();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    return true;
}

void Texture::Bind(uint32 location)
{
    glActiveTexture(GL_TEXTURE0 + location);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture::SetUp()
{
    TearDown();
    glGenTextures(1, &m_textureId);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    m_isInitialized = true;
}

void Texture::TearDown()
{
    if (m_isInitialized)
    {
        glDeleteTextures(1, &m_textureId);
        m_textureId = 0u;
        m_isInitialized = false;
    }
}
} // namespace chill
