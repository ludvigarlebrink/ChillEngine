#include "Water.hpp"
#include "glad/glad.h"

namespace chill
{
Water::Water()
{
}

Water::~Water()
{
}

void Water::Bind()
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void Water::Create(f32 xSize, f32 zSize, f32 height)
{

    WaterVertex* pVertices = new WaterVertex[4];

    pVertices[0].position = glm::vec3(xSize, height, 0.0f);
    pVertices[1].position = glm::vec3(0.0f, height, 0.0f);
    pVertices[2].position = glm::vec3(0.0f, height, zSize);
    pVertices[3].position = glm::vec3(xSize, height, zSize);

    pVertices[0].normal = glm::vec3(0.0f, 1.0f, 0.0f);
    pVertices[1].normal = glm::vec3(0.0f, 1.0f, 0.0f);
    pVertices[2].normal = glm::vec3(0.0f, 1.0f, 0.0f);
    pVertices[3].normal = glm::vec3(0.0f, 1.0f, 0.0f);

    uint32* pElements = new uint32[6];
    m_elementCount = 6;

    pElements[0] = 0u;
    pElements[1] = 1u;
    pElements[2] = 2u;
    pElements[3] = 2u;
    pElements[4] = 3u;
    pElements[5] = 0u;

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(WaterVertex) * 4, pVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32) * m_elementCount, pElements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(WaterVertex), reinterpret_cast<void*>(0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(WaterVertex), reinterpret_cast<void*>(sizeof(glm::vec3)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    delete[] pVertices;
    delete[] pElements;
}

void Water::Render()
{
    glDrawElements(GL_TRIANGLES, m_elementCount, GL_UNSIGNED_INT, 0);
}
}
