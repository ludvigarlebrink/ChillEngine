#pragma once

#include "RenderCoreAPI.hpp"
#include "Math/Math.hpp"
#include "Renderer.hpp"

#include <unordered_map>

namespace chill
{
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
    };

public:

    SpriteRenderer();

    ~SpriteRenderer();

    void Begin();

    void End();

    void Render() override;

    void Submit(Texture* pTexture, const Recti& distRect);

    void Submit(Texture* pTexture, const Recti& sourceRect, const Recti& distRect);

private:

    void SetUp();

    void TearDown();

private:

    bool m_isInitialized;
    int32 m_maxSprites;

    Shader* m_pShader;
    VertexArray* m_pVertexArray;
    std::unordered_map<Texture*, std::vector<SpriteVertex>> m_renderBucket;
};
}
