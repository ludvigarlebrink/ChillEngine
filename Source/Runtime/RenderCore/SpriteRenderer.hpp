#pragma once

#include "RenderCoreAPI.hpp"
#include "Renderer.hpp"

namespace chill
{
class Shader;
class Texture;
class VertexArray;

/**
 * @brief A shader program.
 */
class RENDER_CORE_API SpriteRenderer : public Renderer
{
public:

    SpriteRenderer();

    ~SpriteRenderer();

    void Begin();

    void End();

    void Render() override;

    void Submit(Texture* pTexture);

private:

    VertexArray* m_pVertexArray;

};
}