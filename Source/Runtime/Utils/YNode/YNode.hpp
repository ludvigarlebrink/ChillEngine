#pragma once

#include "../UtilsAPI.hpp"
#include "../BaseTypes.hpp"

#include <string>
#include <vector>

namespace chill
{
class YNodeArray;
class YNodeMap;
class YNodeValue;

/**
 * @brief todo
 */
class UTILS_API YNode
{
public:

    /**
     * @brief Describes the type of a node.
     */
    enum class NodeType
    {
        /**
         * @brief The node is of type YNodeArray.
         */
        ARRAY,

        /**
         * @brief The node is of type YNodeMap.
         */
        MAP,

        /**
         * @brief The node is of type YNodeValue.
         */
        VALUE
    };

private:

    struct Token
    {
        uint64 lineNumber;
        std::string type;
        std::string value;
    };

public:

    virtual ~YNode() = default;

    /**
     * @brief Destroys a node and all of it's children.
     *
     * @param node Node to destroy.
     */
    static void Destroy(YNode* node);

    virtual NodeType GetNodeType() = 0;

    /**
     * @brief
     */
    static YNode* Load(const std::string& filename);

private:

    static bool GenerateTokens(const std::string& code, std::vector<Token>& tokens);

    static bool Parse(const std::vector<Token>& tokens, YNode*& root);

    static bool ParseArray(const std::vector<Token> tokens, uint64& i, YNodeArray* node);

    static bool ParseMap(const std::vector<Token> tokens, uint64& i, YNodeMap* node);
};
} // namespace chill
