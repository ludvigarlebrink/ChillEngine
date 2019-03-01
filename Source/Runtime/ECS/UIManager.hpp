#pragma once

#include "ECSAPI.hpp"
#include "BaseTypes.hpp"

#include <string>

namespace chill
{
class UIWidget
{
public:

    using UICallback = void(*)(void*);
};

class UIImage : public UIWidget
{
public:

    void RegisterOnHoverCallback(void* c, UICallback onHover)
    {
        m_onHover = onHover;
        m_onHoverClass = c;
    }

private:

    UICallback m_onHover;
    void* m_onHoverClass;
};

class ECS_API UIManager final
{
public:

    UIManager();

    ~UIManager();

    bool LoadUI(const std::string& filename);

private:

    void Render();
};
} // namespace chill
