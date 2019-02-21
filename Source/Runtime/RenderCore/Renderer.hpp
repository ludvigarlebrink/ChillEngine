#pragma once

#include "RenderCoreAPI.hpp"

namespace chill
{
class RENDER_CORE_API Renderer
{
public:

    virtual ~Renderer() = default;

    virtual void Render() = 0;
};
} // namespace chill
