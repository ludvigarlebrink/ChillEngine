#include "UIManager.hpp"
#include "YNode/YNode.hpp"
#include "YNode/YNodeArray.hpp"
#include "YNode/YNodeMap.hpp"
#include "YNode/YNodeValue.hpp"

namespace chill
{
UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

bool UIManager::LoadUI(const std::string& filename)
{
    YNode* root = YNode::Load(filename);
    if (!root)
    {
        return false;
    }

    return true;
}

void UIManager::Render()
{
}
} // namespace chill
