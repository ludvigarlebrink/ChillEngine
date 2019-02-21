#pragma once

#include "ECSAPI.hpp"
#include "Renderer.hpp"

#include <unordered_map>

namespace chill
{
class ECS_API RenderManager
{
public:

    RenderManager();

    ~RenderManager();

    template <typename T>
    T* GetRenderer();

private:

    std::unordered_map<size_t, Renderer*> m_renderers;
};

template<typename T>
T* RenderManager::GetRenderer()
{
    return nullptr;
}
} // RenderManager
