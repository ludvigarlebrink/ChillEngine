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
"layout (location = 2) in vec4 color;\n"
"out vec2 vsTexCoord;\n"
"out vec4 vsColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n"
"   vsTexCoord = texCoords;\n"
"   vsColor = color;\n"
"}\0";

static const char* fragmentShaderSource = "#version 450 core\n"
"out vec4 fragColor;\n"
"in vec2 vsTexCoord;\n"
"in vec4 vsColor;\n"
"uniform sampler2D Texture1;\n"
"void main()\n"
"{\n"
"   //vec4 col = texture(Texture1, vsTexCoord);\n"
"   //if (col.a < 0.9) {\n"
"   //    discard;\n"
"   //}\n"
"   fragColor = vsColor;"
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
        if (pTex)
        {
            pTex->Bind(0);
        }

        m_pVertexArray->Render(static_cast<int32>(r.second.size() * 1.5f));
    }

    m_renderBucket.clear();
}

void SpriteRenderer::Submit(const LinearColor& color, const Recti& distRect)
{
    f32 xMin = static_cast<f32>(distRect.x / 800.0f * 2.0f) - 1.0f;
    f32 yMin = static_cast<f32>(distRect.y / 600.0f * 2.0f) - 1.0f;
    f32 xMax = (static_cast<f32>(distRect.x + distRect.w) / 800.0f * 2.0f) - 1.0f;
    f32 yMax = (static_cast<f32>(distRect.y + distRect.h) / 600.0f * 2.0f) - 1.0f;

    SpriteVertex v[4];
    v[0].position = Vector2f(xMin, yMin);
    v[1].position = Vector2f(xMax, yMin);
    v[2].position = Vector2f(xMax, yMax);
    v[3].position = Vector2f(xMin, yMax);

    v[0].textureCoordinates = Vector2f(0.0f, 1.0f);
    v[1].textureCoordinates = Vector2f(1.0f, 1.0f);
    v[2].textureCoordinates = Vector2f(1.0f, 0.0f);
    v[3].textureCoordinates = Vector2f(0.0f, 0.0f);

    // @todo Fix linear color.
    v[0].color = Vector4f(color.r, color.g, color.b, color.a);
    v[1].color = Vector4f(color.r, color.g, color.b, color.a);
    v[2].color = Vector4f(color.r, color.g, color.b, color.a);
    v[3].color = Vector4f(color.r, color.g, color.b, color.a);

    std::vector<SpriteVertex>& vertices = m_renderBucket[nullptr];

    vertices.push_back(v[0]);
    vertices.push_back(v[1]);
    vertices.push_back(v[2]);
    vertices.push_back(v[3]);
}

void SpriteRenderer::Submit(Texture* pTexture, const Recti& distRect)
{
    f32 xMin = static_cast<f32>(distRect.x / 800.0f * 2.0f) - 1.0f;
    f32 yMin = static_cast<f32>(distRect.y / 600.0f * 2.0f) - 1.0f;
    f32 xMax = (static_cast<f32>(distRect.x + distRect.w) / 800.0f * 2.0f) - 1.0f;
    f32 yMax = (static_cast<f32>(distRect.y + distRect.h) / 600.0f * 2.0f) - 1.0f;

    SpriteVertex v[4];
    v[0].position = Vector2f(xMin, yMin);
    v[1].position = Vector2f(xMax, yMin);
    v[2].position = Vector2f(xMax, yMax);
    v[3].position = Vector2f(xMin, yMax);

    v[0].textureCoordinates = Vector2f(0.0f, 1.0f);
    v[1].textureCoordinates = Vector2f(1.0f, 1.0f);
    v[2].textureCoordinates = Vector2f(1.0f, 0.0f);
    v[3].textureCoordinates = Vector2f(0.0f, 0.0f);

    std::vector<SpriteVertex>& vertices = m_renderBucket[pTexture];

    vertices.push_back(v[0]);
    vertices.push_back(v[1]);
    vertices.push_back(v[2]);
    vertices.push_back(v[3]);
}

void SpriteRenderer::Submit(Texture* pTexture, const Recti& sourceRect, const Recti& distRect)
{
    f32 xMin = static_cast<f32>(distRect.x / 800.0f * 2.0f) - 1.0f;
    f32 yMin = static_cast<f32>(distRect.y / 600.0f * 2.0f) - 1.0f;
    f32 xMax = (static_cast<f32>(distRect.x + distRect.w) / 800.0f * 2.0f) - 1.0f;
    f32 yMax = (static_cast<f32>(distRect.y + distRect.h) / 600.0f * 2.0f) - 1.0f;

    SpriteVertex v[4];
    v[0].position = Vector2f(xMin, yMin);
    v[1].position = Vector2f(xMax, yMin);
    v[2].position = Vector2f(xMax, yMax);
    v[3].position = Vector2f(xMin, yMax);
    
    v[0].textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y + sourceRect.h) / static_cast<f32>(pTexture->GetHeight()));
    v[1].textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x + sourceRect.w) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y + sourceRect.h) / static_cast<f32>(pTexture->GetHeight()));
    v[2].textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x + sourceRect.w) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y) / static_cast<f32>(pTexture->GetHeight()));
    v[3].textureCoordinates = Vector2f(static_cast<f32>(sourceRect.x) / static_cast<f32>(pTexture->GetWidth()), static_cast<f32>(sourceRect.y) / static_cast<f32>(pTexture->GetHeight()));

    std::vector<SpriteVertex>& vertices = m_renderBucket[pTexture];

    vertices.push_back(v[0]);
    vertices.push_back(v[1]);
    vertices.push_back(v[2]);
    vertices.push_back(v[3]);
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

    uint32 vertexCounter = 0;
    for (uint32 i = 0u; i < indexCount; i += 6)
    {
        indices[i] = vertexCounter + 0u;
        indices[i + 1] = vertexCounter + 1u;
        indices[i + 2] = vertexCounter + 2u;
        indices[i + 3] = vertexCounter + 2u;
        indices[i + 4] = vertexCounter + 3u;
        indices[i + 5] = vertexCounter + 0u;
        vertexCounter += 4u;
    }

    m_pVertexArray->Load(nullptr, sizeof(SpriteVertex), m_maxSprites * 4, indices, indexCount);
    m_pVertexArray->SetAttribPtr(0, VertexArray::Type::VECTOR2F, 0);
    m_pVertexArray->SetAttribPtr(1, VertexArray::Type::VECTOR2F, sizeof(Vector2f));
    m_pVertexArray->SetAttribPtr(2, VertexArray::Type::VECTOR4F, sizeof(Vector2f) * 2);
    m_pVertexArray->EnableAttribute(0);
    m_pVertexArray->EnableAttribute(1);
    m_pVertexArray->EnableAttribute(2);

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
