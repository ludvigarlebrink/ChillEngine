#include "UIText.hpp"
#include "Font.hpp"
#include "YNode/YNodeValue.hpp"

namespace chill
{
UIText::UIText()
{
    m_pFont = new Font();
    m_pFont->LoadTTF("Data/arial.ttf", 16);
}

UIText::~UIText()
{
    delete m_pFont;
}

Font* UIText::GetFont() const
{
    return m_pFont;
}

std::string UIText::GetText() const
{
    return m_text;
}

UIWidget::Type UIText::GetType() const
{
    return Type::TEXT;
}

void UIText::Load(YNodeMap* pNode)
{
    YNodeValue* pText = pNode->GetChild<YNodeValue>("text");
    if (pText)
    {
        m_text = pText->AsString();
    }
}
} // namespace chill
