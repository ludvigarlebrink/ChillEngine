#pragma once

#include "../EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "UIWidget.hpp"

namespace chill
{
class ENGINE_API UIText : public UIWidget
{
public:

    UIText();

    virtual ~UIText();

    Type GetType() const override;

protected:

    void Load(YNodeMap* pNode) override;
};
} // namespace chill
