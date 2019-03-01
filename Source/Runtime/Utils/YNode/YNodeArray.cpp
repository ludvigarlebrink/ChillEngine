#include "YNodeArray.hpp"

namespace chill
{
YNodeArray::YNodeArray()
{
}

YNodeArray::~YNodeArray()
{
    for (auto& c : m_children)
    {
        if (c)
        {
            delete c;
            c = nullptr;
        }
    }
}

uint64 YNodeArray::GetChildCount() const
{
    return m_children.size();
}

YNodeArray::NodeType YNodeArray::GetNodeType()
{
    return NodeType::ARRAY;
}
} // namespace chill
