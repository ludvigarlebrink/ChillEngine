#pragma once

#include "EngineAPI.hpp"
#include "BaseTypes.hpp"
#include "YNode/YNode.hpp"
#include "YNode/YNodeArray.hpp"
#include "YNode/YNodeMap.hpp"
#include "YNode/YNodeValue.hpp"

#include <string>
#include <unordered_map>

namespace chill
{
class RenderManager;
class SpriteRenderer;
class TextRenderer;
class UIWidget;
class UIImage;

class ENGINE_API UIManager final
{
public:

    UIManager(RenderManager* pRenderManager);

    ~UIManager();

    UIImage* GetImage(const std::string& id);

    bool LoadUI(const std::string& filename);

    void Render();

private:

    UIWidget* Load(YNodeMap* pNode);

    void Render(UIWidget* pWidget);

private:

    UIWidget* m_pRoot;

    std::unordered_map<std::string, UIImage*> m_uiImages;

    SpriteRenderer* m_pSpriteRenderer;
    TextRenderer* m_pTextRenderer;
};
} // namespace chill
