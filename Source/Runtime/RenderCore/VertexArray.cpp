#include "VertexArray.hpp"
#include "glad/glad.h"

namespace chill
{
VertexArray::VertexArray()
    : m_vao(0u)
    , m_vbo(0u)
    , m_ebo(0u)
    , m_vertexSize(0)
    , m_vertexCount(0)
    , m_elementCount(0)
{
}

VertexArray::~VertexArray()
{
    if (m_vao)
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
    }
}

void VertexArray::bind()
{
    glBindVertexArray(m_vao);
}

void VertexArray::enableAttrib(int32 index)
{
    glEnableVertexAttribArray(index);
}

void VertexArray::load(void* pVertexData, int32 vertexSize, int32 vertexCount, uint32* pElementData, int32 elementCount)
{
    m_vertexSize = vertexSize;
    m_vertexCount = vertexCount;
    m_elementCount = elementCount;

    if (m_vao)
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);
        glDeleteBuffers(1, &m_ebo);
    }

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexSize * vertexCount, pVertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32) * elementCount, pElementData, GL_STATIC_DRAW);
}

void* VertexArray::mapForReading()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    return glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
}

void* VertexArray::mapForWriting()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void VertexArray::render()
{
    glDrawElements(GL_TRIANGLES, m_elementCount, GL_UNSIGNED_INT, 0);
}

void VertexArray::render(int32 count, int32 start)
{
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, reinterpret_cast<void*>(start));
}

void VertexArray::setAttribPtr(int32 index, Type type, int32 offset)
{
    switch (type)
    {
    case Type::F32:
        glVertexAttribPointer(index, 1, GL_FLOAT, GL_FALSE, m_vertexSize, reinterpret_cast<void*>(offset));
        break;
    case Type::INT32:
        glVertexAttribPointer(index, 1, GL_INT, GL_FALSE, m_vertexSize, reinterpret_cast<void*>(offset));
        break;
    case Type::VECTOR2F:
        glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, m_vertexSize, reinterpret_cast<void*>(offset));
        break;
    case Type::VECTOR3F:
        glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, m_vertexSize, reinterpret_cast<void*>(offset));
        break;
    case Type::VECTOR4F:
        glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, m_vertexSize, reinterpret_cast<void*>(offset));
        break;
    default:
        break;
    }
}

void VertexArray::unmap()
{
    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
} // namespace chill
