#include "UIImage.hpp"
#include "YNode/YNodeArray.hpp"
#include "YNode/YNodeValue.hpp"

namespace chill
{
UIImage::UIImage()
{
}

UIImage::~UIImage()
{
}

LinearColor UIImage::GetColor() const
{
    return m_color;
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
    YNodeValue* pColorR = pNode->GetChild<YNodeValue>("color.r");
    if (pColorR)
    {
        m_color.r = pColorR->AsFloat();
    }

    YNodeValue* pColorG = pNode->GetChild<YNodeValue>("color.g");
    if (pColorG)
    {
        m_color.g = pColorG->AsFloat();
    }

    YNodeValue* pColorB = pNode->GetChild<YNodeValue>("color.b");
    if (pColorB)
    {
        m_color.b = pColorB->AsFloat();
    }

    YNodeValue* pColorA = pNode->GetChild<YNodeValue>("color.a");
    if (pColorA)
    {
        m_color.a = pColorA->AsFloat();
    }
}
} // namespace chill
