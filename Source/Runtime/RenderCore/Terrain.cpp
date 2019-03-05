#include "Terrain.hpp"
#include "glad/glad.h"

#include <stb/stb_image.h>
#include <iostream>

namespace chill
{
Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}

void Terrain::Bind()
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

bool Terrain::LoadFromHeightMap(const std::string& filename)
{
    int32 format;
    uint8* pData = stbi_load(filename.c_str(), &m_width, &m_height, &format, STBI_grey);

    if (!pData)
    {
        return false;
    }

    TerrainVertex* pVertices = new TerrainVertex[m_width * m_height];
    for (int32 z = 0; z < m_height; ++z)
    {
        for (int32 x = 0; x < m_width; ++x)
        {
            int32 index = z * m_width + x;
            pVertices[index].position = glm::vec3(x, (pData[index] / 255.0f), z);
            pVertices[index].normal = glm::vec3(0.0f, 1.0f, 0.0f);
            pVertices[index].texCoords1 = glm::vec2(x, z);
            pVertices[index].texCoords2 = glm::vec2(x, z);
        }
    }

    // Do not need the heightmap anymore.
    stbi_image_free(pData);

    // Calculate normals.
    for (int32 z = 1; z < m_height - 1; ++z)
    {
        for (int32 x = 1; x < m_width - 1; ++x)
        {
            int32 index = z * m_width + x;
            glm::vec3 normal(0.0f);

            glm::vec3 xAxis = pVertices[z * m_width + (x + 1)].position - pVertices[index].position;
            glm::vec3 zAxis = pVertices[(z + 1) * m_width + x].position - pVertices[index].position;
            normal += glm::cross(glm::normalize(xAxis), glm::normalize(zAxis));

            xAxis = pVertices[(z - 1) * m_width + x].position - pVertices[index].position;
            zAxis = pVertices[z * m_width + (x + 1)].position - pVertices[index].position;
            normal += glm::cross(glm::normalize(xAxis), glm::normalize(zAxis));

            xAxis = pVertices[z * m_width + (x - 1)].position - pVertices[index].position;
            zAxis = pVertices[(z - 1) * m_width + x].position - pVertices[index].position;
            normal += glm::cross(glm::normalize(xAxis), glm::normalize(zAxis));

            xAxis = pVertices[(z + 1) * m_width + x - 1].position - pVertices[index].position;
            zAxis = pVertices[z * m_width + (x - 1)].position - pVertices[index].position;
            normal += glm::cross(glm::normalize(xAxis), glm::normalize(zAxis));

            pVertices[index].normal = normal / 4.0f;
        }
    }

    m_elementCount = static_cast<int32>((m_width - 1) * (m_height - 1) * 6);
    uint32* pElements = new uint32[m_elementCount];

    // Calculate elements.
    int32 counter = 0;
    for (int32 z = 0; z < m_height - 1; ++z)
    {
        for (int32 x = 0; x < m_width - 1; ++x)
        {
            pElements[counter] = z * m_width + (x + 1);
            ++counter;
            pElements[counter] = z * m_width + x;
            ++counter;
            pElements[counter] = (z + 1) * m_width + x;
            ++counter;
            pElements[counter] = (z + 1) * m_width + x;
            ++counter;
            pElements[counter] = (z + 1) * m_width + (x + 1);
            ++counter;
            pElements[counter] = z * m_width + (x + 1);
            ++counter;
        }
    }

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(TerrainVertex) * m_width * m_height, pVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32) * m_elementCount, pElements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), reinterpret_cast<void*>(0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), reinterpret_cast<void*>(sizeof(glm::vec3)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), reinterpret_cast<void*>(sizeof(glm::vec3) * 2));
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), reinterpret_cast<void*>((sizeof(glm::vec3) * 2) + sizeof(glm::vec2)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);

    delete[] pVertices;
    delete[] pElements;
    return true;
}

void Terrain::Render()
{
    glDrawElements(GL_TRIANGLES, m_elementCount, GL_UNSIGNED_INT, 0);
}
} // namespace chill
