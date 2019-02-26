#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Renderer.hpp"
#include "Math/Math.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"

#include <string>
#include <unordered_map>

namespace chill
{
class Font;

class RENDER_CORE_API TextRenderer final : public Renderer
{
private:

    struct GlyphVertex
    {
        Vector2f position;
        Vector2f textureCoordiantes;
    };

public:

    TextRenderer();

    ~TextRenderer();

    void Begin();

    void End();

    void Render() override;

    void Submit(const std::string& text, Font* pTexture, const Vector2f& position);

private:

    void SetUp();

    void TearDown();

private:

    bool m_isInitialized;
    int32 m_maxCharacters;

    Shader* m_pShader;
    VertexArray* m_pVertexArray;
    std::unordered_map<Font*, std::vector<GlyphVertex>> m_renderBucket;
};
} // namespace chill
