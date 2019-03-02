#include "UIImage.hpp"

namespace chill
{
UIImage::UIImage()
{
}

UIImage::~UIImage()
{
}

UIWidget::Type UIImage::GetType() const
{
    return Type::IMAGE;
}

void UIImage::RegisterOnHoverCallback(void* pUserPointer, UICallback onHover)
{
    m_onHover = onHover;
    m_pOnHoverUserPointer = pUserPointer;
}

void UIImage::Load(YNodeMap* pNode)
{
}
} // namespace chill
