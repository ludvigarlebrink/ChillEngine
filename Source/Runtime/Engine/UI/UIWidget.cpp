#include "UIWidget.hpp"

namespace chill
{
UIWidget::UIWidget()
    : m_height(600)
    , m_width(800)
    , m_enabled(true)
    , m_useParentHeight(false)
    , m_useParentWidth(false)
{
}

Vector2f UIWidget::GetAnchor()
{
    return m_anchor;
}

Vector2f UIWidget::GetPivot()
{
    return m_pivot;
}

Vector2f UIWidget::GetPosition()
{
    return m_position;
}

bool UIWidget::IsEnabled() const
{
    return m_enabled;
}
} // namespace chill
