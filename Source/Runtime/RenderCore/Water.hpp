#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace chill
{
/**
 * @brief A water mesh.
 */
class RENDER_CORE_API Water
{
public:

    struct WaterVertex
    {
        glm::vec3 position;
        glm::vec3 normal;
    };

public:

    Water();

    virtual ~Water();

    void Bind();

    void Create(f32 xSize, f32 zSize, f32 height);

    void Render();

private:

    f32 m_xSize;
    f32 m_zSize;
    f32 m_height;
    uint32 m_vao;
    uint32 m_vbo;
    uint32 m_ebo;
    int32 m_elementCount;
};
} // namespace chill
