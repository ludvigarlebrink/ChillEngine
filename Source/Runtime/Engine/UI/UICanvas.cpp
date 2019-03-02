#include "UICanvas.hpp"

namespace chill
{
UICanvas::UICanvas()
{
}

UICanvas::~UICanvas()
{
}

UIWidget::Type UICanvas::GetType() const
{
    return Type::CANVAS;
}

void UICanvas::Load(YNodeMap* pNode)
{
}
} // namespace chill
