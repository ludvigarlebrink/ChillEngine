#pragma once

#include "../EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "UIWidget.hpp"

#include <vector>

namespace chill
{
class UIManager;

class ENGINE_API UICanvas : public UIWidget
{
    friend UIManager;

public:

    UICanvas();

    virtual ~UICanvas();

    Type GetType() const override;

protected:

    void Load(YNodeMap* pNode) override;
};
} // namespace chill
