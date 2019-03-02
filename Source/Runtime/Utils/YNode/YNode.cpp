#include "YNode.hpp"
#include "YNodeArray.hpp"
#include "YNodeMap.hpp"
#include "YNodeValue.hpp"

#include <fstream>
#include <iostream>
#include <streambuf>

namespace chill
{
void YNode::Destroy(YNode* node)
{
    delete node;
}

YNode* YNode::Load(const std::string& filename)
{
    std::ifstream t(filename);
    std::string code((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    std::vector<Token> tokens;
    if (!GenerateTokens(code, tokens))
    {
        return nullptr;
    }

    YNode* root;
    if (!Parse(tokens, root))
    {
        return nullptr;
    }

    return root;
}

bool YNode::GenerateTokens(const std::string& code, std::vector<Token>& tokens)
{
    uint64 lineNumber = 1u;
    uint64 i = 0u;
    while (i < code.length())
    {
        // Ignore white space.
        if (code[i] == ' ' || code[i] == '\t')
        {
            ++i;
            continue;
        }

        // Increment line number used for debugging.
        if (code[i] == '\n')
        {
            ++lineNumber;
            ++i;
            continue;
        }

        // Operators.
        if (code[i] == ',' || code[i] == '=' || code[i] == '{' || code[i] == '}' || code[i] == '[' || code[i] == ']')
        {
            std::string v = "";
            v += code[i];
            tokens.push_back({ lineNumber, "operator", v });
            ++i;
            continue;
        }

        // Name.
        if ((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || code[i] == '_')
        {
            std::string name = "";
            name += code[i];
            ++i;

            while (((code[i] >= '0' && code[i] <= '9') || (code[i] >= 'a' && code[i] <= 'z') ||
                (code[i] >= 'A' && code[i] <= 'Z') || code[i] == '_' || code[i] == '.') && i < code.size())
            {
                name += code[i];
                ++i;
            }

            tokens.push_back({ lineNumber, "name", name });
            continue;
        }

        // Number.
        if ((code[i] >= '0' && code[i] <= '9') || code[i] == '-')
        {
            std::string number = "";
            number += code[i];
            bool is_float = false;
            ++i;

            while (((code[i] >= '0' && code[i] <= '9') || code[i] == '.') && i < code.size())
            {
                if (code[i] == '.')
                {
                    is_float = true;
                }

                number += code[i];
                ++i;
            }

            if (is_float)
            {
                tokens.push_back({ lineNumber, "float", number });
            }
            else
            {
                tokens.push_back({ lineNumber, "int", number });
            }
            continue;
        }

        // String.
        if (code[i] == '\"')
        {
            ++i;
            std::string str = "";

            while (code[i] != '\"' && i < code.size())
            {
                str += code[i];
                ++i;
            }

            // Eat ".
            ++i;

            tokens.push_back({ lineNumber, "string", str });
            continue;
        }

        // Error in code. Break.
        std::cout << "Error at line: " << lineNumber << ". Unresolved symbol: " << code[i] << "\n";
        return false;
    }
}

bool YNode::Parse(const std::vector<Token>& tokens, YNode*& root)
{
    uint64 i = 0u;

    if (tokens[i].type != "name")
    {
        std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing key.\n";
        return false;
    }
    ++i;

    if (tokens[i].value != "=")
    {
        std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: =\n";
        return false;
    }
    ++i;

    if (tokens[i].value == "[")
    {
        ++i;
        YNodeArray* r = new YNodeArray();
        ParseArray(tokens, i, r);
        root = r;
    }
    else if (tokens[i].value == "{")
    {
        ++i;
        YNodeMap* r = new YNodeMap();
        ParseMap(tokens, i, r);
        root = r;
    }
    else
    {
        std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: { or [\n";
        return false;
    }

    return true;
}

bool YNode::ParseArray(const std::vector<Token> tokens, uint64& i, YNodeArray* node)
{
    while (i < tokens.size())
    {
        if (tokens[i].value == "[")
        {
            ++i;
            YNodeArray* n = new YNodeArray();
            if (!ParseArray(tokens, i, n))
            {
                delete n;
                return false;
            }
            node->m_children.push_back(n);

            if (tokens[i].value == ",")
            {
                ++i;
                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }
                continue;
            }

            if (tokens[i].value == "]")
            {
                ++i;
                return true;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
            return false;
        }

        if (tokens[i].value == "{")
        {
            ++i;
            YNodeMap* n = new YNodeMap();
            if (!ParseMap(tokens, i, n))
            {
                delete n;
                return false;
            }
            node->m_children.push_back(n);

            if (tokens[i].value == ",")
            {
                ++i;
                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }
                continue;
            }

            if (tokens[i].value == "]")
            {
                ++i;
                return true;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
            return false;
        }

        if (tokens[i].type == "name")
        {
            if (tokens[i].value == "true" || tokens[i].value == "false")
            {
                YNodeValue* n = new YNodeValue();
                n->m_value = tokens[i].value;
                n->m_valueType = YNodeValue::ValueType::BOOL;
                node->m_children.push_back(n);
                ++i;

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "]")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
                return false;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Expected bool: true or false\n";
            return false;
        }

        if (tokens[i].type == "float")
        {
            YNodeValue* n = new YNodeValue();
            n->m_value = tokens[i].value;
            n->m_valueType = YNodeValue::ValueType::FLOAT;
            node->m_children.push_back(n);
            ++i;

            if (tokens[i].value == ",")
            {
                ++i;
                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }
                continue;
            }

            if (tokens[i].value == "]")
            {
                ++i;
                return true;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
            return false;
        }

        if (tokens[i].type == "int")
        {
            YNodeValue* n = new YNodeValue();
            n->m_value = tokens[i].value;
            n->m_valueType = YNodeValue::ValueType::INT;
            node->m_children.push_back(n);
            ++i;

            if (tokens[i].value == ",")
            {
                ++i;
                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }
                continue;
            }

            if (tokens[i].value == "]")
            {
                ++i;
                return true;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
            return false;
        }

        if (tokens[i].type == "string")
        {
            YNodeValue* n = new YNodeValue();
            n->m_value = tokens[i].value;
            n->m_valueType = YNodeValue::ValueType::STRING;
            node->m_children.push_back(n);
            ++i;

            if (tokens[i].value == ",")
            {
                ++i;
                if (tokens[i].value == "]")
                {
                    ++i;
                    return true;
                }
                continue;
            }

            if (tokens[i].value == "]")
            {
                ++i;
                return true;
            }

            std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: ] or ,\n";
            return false;
        }
    }

    return true;
}

bool YNode::ParseMap(const std::vector<Token> tokens, uint64& i, YNodeMap* node)
{
    while (i < tokens.size())
    {
        if (tokens[i].type == "name")
        {
            std::string name = tokens[i].value;
            ++i;

            if (tokens[i].value != "=")
            {
                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: =\n";
                return false;
            }
            ++i;

            if (tokens[i].value == "[")
            {
                ++i;
                YNodeArray* n = new YNodeArray();
                if (!ParseArray(tokens, i, n))
                {
                    delete n;
                    return false;
                }
                node->m_children.insert({ name, n });

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "}")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                return false;
            }

            if (tokens[i].value == "{")
            {
                ++i;
                YNodeMap* n = new YNodeMap();
                if (!ParseMap(tokens, i, n))
                {
                    delete n;
                    return false;
                }
                node->m_children.insert({ name, n });

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "}")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                return false;
            }

            if (tokens[i].type == "name")
            {
                if (tokens[i].value == "true" || tokens[i].value == "false")
                {

                    YNodeValue* n = new YNodeValue();
                    n->m_value = tokens[i].value;
                    n->m_valueType = YNodeValue::ValueType::BOOL;
                    node->m_children.insert({ name, n });
                    ++i;

                    if (tokens[i].value == ",")
                    {
                        ++i;
                        if (tokens[i].value == "}")
                        {
                            ++i;
                            return true;
                        }
                        continue;
                    }

                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }

                    std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                    return false;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Expected bool: true or false\n";
                return false;
            }

            if (tokens[i].type == "float")
            {
                YNodeValue* n = new YNodeValue();
                n->m_value = tokens[i].value;
                n->m_valueType = YNodeValue::ValueType::FLOAT;
                node->m_children.insert({ name, n });
                ++i;

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "}")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                return false;
            }

            if (tokens[i].type == "int")
            {
                YNodeValue* n = new YNodeValue();
                n->m_value = tokens[i].value;
                n->m_valueType = YNodeValue::ValueType::INT;
                node->m_children.insert({ name, n });
                ++i;

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "}")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                return false;
            }

            if (tokens[i].type == "string")
            {
                YNodeValue* n = new YNodeValue();
                n->m_value = tokens[i].value;
                n->m_valueType = YNodeValue::ValueType::STRING;
                node->m_children.insert({ name, n });
                ++i;

                if (tokens[i].value == ",")
                {
                    ++i;
                    if (tokens[i].value == "}")
                    {
                        ++i;
                        return true;
                    }
                    continue;
                }

                if (tokens[i].value == "}")
                {
                    ++i;
                    return true;
                }

                std::cout << "Error at line: " << tokens[i].lineNumber << ". Missing symbol: } or ,\n";
                return false;
            }
        }
    }

    return true;
}
} // namespace chill
