#pragma once

#include "EngineAPI.hpp"
#include "BaseTypes.hpp"

namespace chill
{
class ECSManager;
class RenderManager;

class ENGINE_API System
{
    friend ECSManager;

public:

    struct SystemInfo
    {
        bool update;
        bool render;
    };

public:

    virtual ~System() = default;

protected:

    virtual void OnStart(ECSManager& ecsManager);

    virtual void OnRender(ECSManager& ecsManager, RenderManager& renderManager);

    virtual void OnTick(f32 deltaTime, ECSManager& ecsManager);

    virtual SystemInfo SetUpSystem() = 0;
};
} // namespace chill
