#pragma once

#include "../EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "Math/Math.hpp"
#include "YNode/YNodeMap.hpp"

#include <vector>

namespace chill
{
class UIManager;

class ENGINE_API UIWidget
{
    friend UIManager;

public:

    enum class Type
    {
        CANVAS,
        IMAGE,
        TEXT
    };

    using UICallback = void(*)(void*);

public:

    UIWidget();

    virtual ~UIWidget() = default;

    Vector2f GetAnchor();

    Vector2f GetPivot();

    Vector2f GetPosition();

    virtual Type GetType() const = 0;

    bool IsEnabled() const;


protected:

    virtual void Load(YNodeMap* pNode) = 0;

private:

    Vector2f m_anchor;
    Vector2f m_pivot;
    Vector2f m_position;
    f32 m_width;
    f32 m_height;

    bool m_enabled;
    bool m_useParentHeight;
    bool m_useParentWidth;

    std::vector<UIWidget*> m_children;
};
} // namespace chill
