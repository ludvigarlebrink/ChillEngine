#pragma once

#include "RenderCoreAPI.hpp"
#include "Math/Math.hpp"
#include "Renderer.hpp"

#include <unordered_map>
#include <vector>

namespace chill
{
class Font;
class Shader;
class Texture;
class VertexArray;

/**
 * @brief A shader program.
 */
class RENDER_CORE_API SpriteRenderer final : public Renderer
{
private:

    struct SpriteVertex
    {
        Vector2f position;
        Vector2f textureCoordinates;
        LinearColor color;
    };

public:

    SpriteRenderer();

    ~SpriteRenderer();

    void Render() override;

    void Submit(const LinearColor& color, const Recti& distRect);

    void Submit(Texture* pTexture, const Recti& distRect);

    void Submit(Texture* pTexture, const Recti& sourceRect, const Recti& distRect);

    void Submit(const std::string& text, Font* pFont, const Vector2f& position, const LinearColor& color);

private:

    void SetUp();

    void TearDown();

private:

    bool m_isInitialized;
    int32 m_maxSprites;

    Shader* m_pShader;
    VertexArray* m_pVertexArray;
    
    std::vector<std::pair<Texture*, std::vector<SpriteVertex>>> m_backToFront;
};
}
