#pragma once

#include "../EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "UIWidget.hpp"

namespace chill
{
class Font;

class ENGINE_API UIText : public UIWidget
{
public:

    UIText();

    virtual ~UIText();

    Font* GetFont() const;

    std::string GetText() const;

    Type GetType() const override;

protected:

    void Load(YNodeMap* pNode) override;

private:

    Font* m_pFont;
    std::string m_text;
};
} // namespace chill
