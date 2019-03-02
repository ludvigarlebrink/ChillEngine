#include "UIText.hpp"

namespace chill
{
UIText::UIText()
{
}

UIText::~UIText()
{
}

UIWidget::Type UIText::GetType() const
{
    return Type::CANVAS;
}

void UIText::Load(YNodeMap* pNode)
{
}
} // namespace chill
