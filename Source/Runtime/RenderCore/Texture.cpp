#include "Texture.hpp"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace chill
{
Texture::Texture()
    : m_isInitialized(false)
    , m_format(Format::RGBA)
    , m_height(0)
    , m_width(0)
    , m_textureId(0u)
{
}

Texture::~Texture()
{
    TearDown();
}

void Texture::Create(int32 width, int32 height, Format format, void* pData)
{
    SetUp();
    m_width = width;
    m_height = height;
    m_format = format;
    uint32 glFormat = ToGLFormat(m_format);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_width, m_height, 0, GL_RED, GL_UNSIGNED_BYTE, pData);
}

void Texture::CreateSubTexture(int32 xOffset, int32 yOffset, int32 width, int32 height, void* pData)
{
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    glTexSubImage2D(GL_TEXTURE_2D, 0, xOffset, yOffset, width, height, ToGLFormat(m_format), GL_UNSIGNED_BYTE, pData);
}

Texture::Format Texture::GetFormat() const
{
    return m_format;
}

int32 Texture::GetHeight() const
{
    return m_height;
}

int32 Texture::GetWidth() const
{
    return m_width;
}

bool Texture::LoadFromFile(const std::string& filename)
{
    int32 format = 0;
    uint8* pData = stbi_load(filename.c_str(), &m_width, &m_height, &format, STBI_rgb_alpha);
    if (!pData)
    {
        return false;
    }

    switch (format)
    {
    case STBI_rgb:
        m_format = Format::RGB;
        break;
    case STBI_rgb_alpha:
        m_format = Format::RGBA;
        break;
    default:
        break;
    }

    SetUp();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pData);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(pData);

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
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

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
uint32 Texture::ToGLFormat(Format format)
{
    switch (m_format)
    {
    case Format::R:
        return GL_RED;
    case Format::RG:
        return GL_RG;
    case Format::RGB:
        return GL_RGB;
    case Format::RGBA:
        return GL_RGBA;
    default:
        break;
    }
}
} // namespace chill
