#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace chill
{
/**
 * @brief A terrain.
 */
class RENDER_CORE_API Terrain
{
public:

    struct TerrainVertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords1;
        glm::vec2 texCoords2;
    };

public:

    Terrain();

    virtual ~Terrain();

    void Bind();

    bool LoadFromHeightMap(const std::string& filename);

    void Render();

private:

    uint32 m_vao;
    uint32 m_vbo;
    uint32 m_ebo;
    int32 m_height;
    int32 m_width;
    int32 m_elementCount;
};
} // namespace chill
