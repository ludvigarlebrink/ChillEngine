#pragma once

#include "../BaseTypes.hpp"
#include "../UtilsAPI.hpp"
#include "YNode.hpp"

#include <vector>

namespace chill
{
class UTILS_API YNodeArray final : public YNode
{
    friend YNode;

public:

    YNodeArray();

    ~YNodeArray();

    template <typename T>
    T* GetChild(uint64 index) const;

    uint64 GetChildCount() const;

    NodeType GetNodeType() override;

private:

    std::vector<YNode*> m_children;
};

template<typename T>
T* YNodeArray::GetChild(uint64 index) const
{
    if (index < 0u || index >= m_children.size())
    {
        return nullptr;
    }

    return dynamic_cast<T*>(m_children[index]);
}
} // namespace chill
