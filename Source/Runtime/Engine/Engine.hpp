#pragma once

#include "EngineAPI.hpp"

namespace chill
{
class ECSManager;
class RenderManager;
class UIManager;

class ENGINE_API Engine
{
public:

    Engine();

    ~Engine();

    void Run();

    void SetUp();

    void TearDown();

private:

    ECSManager* m_pECSManager;
    RenderManager* m_pRenderManager;
    UIManager* m_pUIManager;
};
}
