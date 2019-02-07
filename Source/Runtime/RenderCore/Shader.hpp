#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

namespace chill
{
/**
 * @brief A shader program.
 */
class RENDER_CORE_API Shader
{
public:

    Shader();

    virtual ~Shader();

public:

    int32 m_shaderProgram;
};
} // namespace chill
