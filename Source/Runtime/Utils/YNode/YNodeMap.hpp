#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"
#include "YNode.hpp"

#include <unordered_map>

namespace chill
{
class UTILS_API YNodeMap final : public YNode
{
    friend YNode;

public:

    YNodeMap();

    ~YNodeMap();

    template <typename T>
    T* GetChild(const std::string& key);

    NodeType GetNodeType() override;

private:

    std::unordered_map<std::string, YNode*> m_children;
};

template<typename T>
T* YNodeMap::GetChild(const std::string& key)
{
    auto it = m_children.find(key);
    if (it != m_children.end())
    {
        return dynamic_cast<T*>(it->second);
    }

    return nullptr;
}
} // namespace chill