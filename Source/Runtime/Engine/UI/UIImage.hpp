#pragma once

#include "../EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "UIWidget.hpp"

namespace chill
{
class ENGINE_API UIImage : public UIWidget
{
public:

    UIImage();

    virtual ~UIImage();

    Type GetType() const override;

    void RegisterOnHoverCallback(void* pUserPointer, UICallback onHover);

protected:

    void Load(YNodeMap* pNode) override;

private:

    UICallback m_onHover;
    void* m_pOnHoverUserPointer;
};
} // namespace chill
