#include "YNodeMap.hpp"

namespace chill
{
YNodeMap::YNodeMap()
{
}

YNodeMap::~YNodeMap()
{
    for (auto& c : m_children)
    {
        if (c.second)
        {
            delete c.second;
            c.second = nullptr;
        }
    }
}

YNodeMap::NodeType YNodeMap::GetNodeType()
{
    return NodeType::MAP;
}
} // namespace chill
