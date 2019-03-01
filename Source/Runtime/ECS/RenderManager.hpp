#pragma once

#include "ECSAPI.hpp"
#include "Renderer.hpp"

#include <typeinfo>
#include <unordered_map>

namespace chill
{
class ECS_API RenderManager final
{
public:

    RenderManager();

    ~RenderManager();

    template <typename T>
    T* AddRenderer();

    template <typename T>
    T* GetRenderer();

private:

    void Render();

private:

    std::unordered_map<size_t, Renderer*> m_renderers;
    std::vector<Renderer*> m_transparencyPass;
};

template<typename T>
T* RenderManager::AddRenderer()
{
    T* pRenderer = new T();
    m_renderers.insert({ typeid(T).hash_code(), pRenderer });
    return pRenderer;
}

template<typename T>
T* RenderManager::GetRenderer()
{
    auto itr = m_renderers.find(typeid(T).hash_code());
    if (itr != m_renderers.end())
    {
        return static_cast<T*>(itr->second);
    }
    return nullptr;
}
} // RenderManager
