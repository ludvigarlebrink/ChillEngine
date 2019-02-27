#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Math/Math.hpp"
#include "Renderer.hpp"

#include <string>

namespace chill
{
class Texture;

class RENDER_CORE_API Font final
{
public:

    struct Character
    {
        Vector2i size;
        Vector2i bearing;
        Vector2f texturePosition;
        Vector2f textureSize;
        uint32 advance;
    };

public:

    Font();

    ~Font();

    void Bind(uint32 location);

    Character GetCharacter(uchar character) const;

    Texture* GetTexture() const;

    void LoadTTF(const std::string& filename, int32 fontSize);

private:

    int32 m_fontSize;

    Character m_characters[128];
    Texture* m_pTexture;
};
} // namespace chill
