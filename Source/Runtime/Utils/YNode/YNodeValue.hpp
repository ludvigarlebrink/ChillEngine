#pragma once

#include "../UtilsAPI.hpp"
#include "YNode.hpp"

namespace chill
{
class UTILS_API YNodeValue final : public YNode
{
    friend YNode;

public:

    enum class ValueType
    {
        BOOL,
        FLOAT,
        INT,
        STRING
    };

public:

    YNodeValue();

    ~YNodeValue();

    bool AsBool() const;

    f32 AsFloat() const;

    int32 AsInt() const;

    std::string AsString() const;
    
    NodeType GetNodeType() override;

    ValueType GetValueType() const;

private:

    ValueType m_valueType;
    std::string m_value;
};
} // namespace chill
