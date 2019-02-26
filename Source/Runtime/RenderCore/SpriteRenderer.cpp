#include "SpriteRenderer.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"

#include <iostream>

namespace chill
{
static const char* vertexShaderSource = "#version 450 core\n"
"layout (location = 0) in vec2 position;\n"
"layout (location = 1) in vec2 texCoords;\n"
"out vec2 vsTexCoord;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n"
"   vsTexCoord = texCoords;\n"
"}\0";

static const char* fragmentShaderSource = "#version 450 core\n"
"out vec4 fragColor;\n"
"in vec2 vsTexCoord;\n"
"uniform sampler2D Texture1;\n"
"void main()\n"
"{\n"
"   vec4 col = texture(Texture1, vsTexCoord);\n"
"   if (col.a < 0.9) {\n"
"       discard;\n"
"   }\n"
"   fragColor = col;"
"}\n\0";

SpriteRenderer::SpriteRenderer()
    : m_isInitialized(false)
    , m_maxSprites(2048)
    , m_pShader(nullptr)
    , m_pVertexArray(nullptr)
{
    SetUp();
}

SpriteRenderer::~SpriteRenderer()
{
    TearDown();
}

void SpriteRenderer::Begin()
{
    m_renderBucket.clear();
}

void SpriteRenderer::End()
{
}

void SpriteRenderer::Render()
{
    m_pShader->Use();
    m_pShader->SetIntSlow("Texture1", 0);

    m_pVertexArray->Bind();

    for (auto r : m_renderBucket)
    {
        SpriteVertex* pVert = static_cast<SpriteVertex*>(m_pVertexArray->MapForWriting());
        memcpy(pVert, r.second.data(), sizeof(SpriteVertex) * r.second.size());
        m_pVertexArray->Unmap();
        Texture* pTex = r.first;
        pTex->Bind(0);
        m_pVertexArray->Render(static_cast<int32>(r.second.size() * 1.5f));
    }
}

void SpriteRenderer::Submit(Texture* pTexture, const Recti& distRect)
{
    SpriteVertex v1 = {};
    v1.position = Vector2f(static_cast<f32>(distRect.x / 800.0f) - 1.0f, static_cast<f32>(distRect.y / 600.0f) - 1.0f);
    v1.textureCoordinates = Vector2f(0.0f, 1.0f);

    SpriteVertex v2 = {};
    v2.position = Vector2f((static_cast<f32>(distRect.x + distRect.w) / 800.0f) - 1.0f, static_cast<f32>(distRect.y / 600.0f) - 1.0f);
    v2.textureCoordinates = Vector2f(1.0f, 1.0f);

    SpriteVertex v3 = {};
    v3.position = Vector2f((static_cast<f32>(distRect.x + distRect.w) / 800.0f) - 1.0f, (static_cast<f32>(distRect.y + distRect.h) / 600.0f) - 1.0f);
    v3.textureCoordinates = Vector2f(1.0f, 0.0f);

    SpriteVertex v4 = {};
    v4.position = Vector2f(static_cast<f32>(distRect.x / 800.0f) - 1.0f, (static_cast<f32>(distRect.y + distRect.h) / 600.0f) - 1.0f);
    v4.textureCoordinates = Vector2f(0.0f, 0.0f);

    std::vector<SpriteVertex>& vertices = m_renderBucket[pTexture];

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
}

void SpriteRenderer::Submit(Texture* pTexture, const Recti& sourceRect, const Recti& distRect)
{
    SpriteVertex v1 = {};
    v1.position = Vector2f(static_cast<f32>(distRect.x / 800.0f) - 1.0f, static_cast<f32>(distRect.y / 600.0f) - 1.0f);
    v1.textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y + sourceRect.h) / static_cast<f32>(pTexture->GetHeight()));

    SpriteVertex v2 = {};
    v2.position = Vector2f((static_cast<f32>(distRect.x + distRect.w) / 800.0f) - 1.0f, static_cast<f32>(distRect.y / 600.0f) - 1.0f);
    v2.textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x + sourceRect.w) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y + sourceRect.h) / static_cast<f32>(pTexture->GetHeight()));

    SpriteVertex v3 = {};
    v3.position = Vector2f((static_cast<f32>(distRect.x + distRect.w) / 800.0f) - 1.0f, (static_cast<f32>(distRect.y + distRect.h) / 600.0f) - 1.0f);
    v3.textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x + sourceRect.w) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y) / static_cast<f32>(pTexture->GetHeight()));

    SpriteVertex v4 = {};
    v4.position = Vector2f(static_cast<f32>(distRect.x / 800.0f) - 1.0f, (static_cast<f32>(distRect.y + distRect.h) / 600.0f) - 1.0f);
    v1.textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y) / static_cast<f32>(pTexture->GetHeight()));

    std::vector<SpriteVertex>& vertices = m_renderBucket[pTexture];

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
}

void SpriteRenderer::SetUp()
{
    TearDown();

    m_pShader = new Shader();

    if (!m_pShader->LoadFromString(vertexShaderSource, fragmentShaderSource))
    {
        std::cout << "something went wrong\n";
    }

    m_pVertexArray = new VertexArray();

    uint32 indexCount = m_maxSprites * 6;
    uint32* indices = new uint32[indexCount];

    for (uint32 i = 0u; i < indexCount; i += 6)
    {
        indices[i] = i + 0u;
        indices[i + 1] = i + 1u;
        indices[i + 2] = i + 2u;
        indices[i + 3] = i + 2u;
        indices[i + 4] = i + 3u;
        indices[i + 5] = i + 0u;
    }

    m_pVertexArray->Load(nullptr, sizeof(SpriteVertex), m_maxSprites * 4, indices, indexCount);
    m_pVertexArray->SetAttribPtr(0, VertexArray::Type::VECTOR2F, 0);
    m_pVertexArray->SetAttribPtr(1, VertexArray::Type::VECTOR2F, sizeof(Vector2f));
    m_pVertexArray->EnableAttribute(0);
    m_pVertexArray->EnableAttribute(1);

    delete indices;
    m_isInitialized = true;
}

void SpriteRenderer::TearDown()
{
    if (m_isInitialized)
    {
        delete m_pShader;
        delete m_pVertexArray;
        m_isInitialized = false;
    }
}
} // namespace chill
