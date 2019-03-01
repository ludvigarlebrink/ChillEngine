#include "YNodeValue.hpp"

namespace chill
{
YNodeValue::YNodeValue()
{
}

YNodeValue::~YNodeValue()
{
}

bool YNodeValue::AsBool() const
{
    if (m_value == "true")
    {
        return true;
    }

    return false;
}

f32 YNodeValue::AsFloat() const
{
    return atof(m_value.c_str());
}

int32 YNodeValue::AsInt() const
{
    return atoi(m_value.c_str());
}

std::string YNodeValue::AsString() const
{
    return m_value;
}

YNodeValue::NodeType YNodeValue::GetNodeType()
{
    return NodeType::VALUE;
}

YNodeValue::ValueType YNodeValue::GetValueType() const
{
    return m_valueType;
}
} // namespace chill
