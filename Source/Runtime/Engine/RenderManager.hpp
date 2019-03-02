#pragma once

#include "EngineAPI.hpp"
#include "Renderer.hpp"

#include <typeinfo>
#include <unordered_map>

namespace chill
{
class Engine;

class ENGINE_API RenderManager final
{
    friend Engine;

public:

    RenderManager();

    ~RenderManager();

    template <typename T>
    T* GetRenderer();

private:

    void Render();

private:

    std::unordered_map<size_t, Renderer*> m_renderers;
};

template<typename T>
T* RenderManager::GetRenderer()
{
    auto itr = m_renderers.find(typeid(T).hash_code());
    if (itr != m_renderers.end())
    {
        return static_cast<T*>(itr->second);
    }

    T* pRenderer = new T();
    m_renderers.insert({ typeid(T).hash_code(), pRenderer });
    return pRenderer;
}
} // RenderManager
