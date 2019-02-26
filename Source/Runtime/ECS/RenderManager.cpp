#include "RenderManager.hpp"

namespace chill
{
RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::Render()
{
    // Render all in transparency pass.
    for (auto r : m_transparencyPass)
    {
        r->Render();
    }
}
} // namespace chill
