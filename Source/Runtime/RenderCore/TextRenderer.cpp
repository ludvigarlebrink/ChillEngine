#include "TextRenderer.hpp"

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

TextRenderer::TextRenderer()
    : m_isInitialized(false)
    , m_maxCharacters(4096)
    , m_pShader(nullptr)
    , m_pVertexArray(nullptr)
{
    SetUp();
}

TextRenderer::~TextRenderer()
{
    TearDown();
}

void TextRenderer::Begin()
{
    m_renderBucket.clear();
}

void TextRenderer::End()
{
}

void TextRenderer::Render()
{
}

void TextRenderer::Submit(const std::string& text, Font* pTexture, const Vector2f& position)
{
    for (auto c : text)
    {
        
    }
}
void TextRenderer::SetUp()
{
    TearDown();

    m_pShader = new Shader();

    if (!m_pShader->LoadFromString(vertexShaderSource, fragmentShaderSource))
    {
        std::cout << "something went wrong\n";
    }

    m_pVertexArray = new VertexArray();

    uint32 indexCount = m_maxCharacters * 6;
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

    m_pVertexArray->Load(nullptr, sizeof(GlyphVertex), m_maxCharacters * 4, indices, indexCount);
    m_pVertexArray->SetAttribPtr(0, VertexArray::Type::VECTOR2F, 0);
    m_pVertexArray->SetAttribPtr(1, VertexArray::Type::VECTOR2F, sizeof(Vector2f));
    m_pVertexArray->EnableAttribute(0);
    m_pVertexArray->EnableAttribute(1);

    delete indices;
    m_isInitialized = true;
}

void TextRenderer::TearDown()
{
    if (m_isInitialized)
    {
        delete m_pShader;
        delete m_pVertexArray;
        m_isInitialized = false;
    }
}
} // namespace chill
