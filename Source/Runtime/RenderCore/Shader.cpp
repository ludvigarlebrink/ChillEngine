#include "Shader.hpp"
#include "Math/Math.hpp"
#include "glad/glad.h"

#include <fstream>
#include <streambuf>
#include <iostream>

namespace chill
{
uint32 Shader::m_activeShaderProgram = 0u;

Shader::Shader()
    : m_shaderProgram(0u)
{    
}

Shader::~Shader()
{
    if (m_shaderProgram)
    {
        glDeleteProgram(m_shaderProgram);
        m_shaderProgram = 0u;
    }
}

uint32 Shader::GetUniformLocation(const std::string& name) const
{
    return glGetUniformLocation(m_shaderProgram, name.c_str());
}

bool Shader::Load(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename)
{
    return Load(vertexShaderFilename, "", fragmentShaderFilename);
}

bool Shader::Load(const std::string& vertexShaderFilename, const std::string& geometryShaderFilename, const std::string& fragmentShaderFilename)
{
    std::ifstream vert(vertexShaderFilename);
    if (!vert.is_open())
    {
        return false;
    }

    std::string vertSource((std::istreambuf_iterator<char>(vert)), std::istreambuf_iterator<char>());
    vert.close();

    std::ifstream frag(vertexShaderFilename);
    if (!frag.is_open())
    {
        return false;
    }

    std::string fragSource((std::istreambuf_iterator<char>(vert)), std::istreambuf_iterator<char>());
    frag.close();

    if (!geometryShaderFilename.empty())
    {
        std::ifstream geom(vertexShaderFilename);
        if (!geom.is_open())
        {
            return false;
        }

        std::string geomSource((std::istreambuf_iterator<char>(vert)), std::istreambuf_iterator<char>());
        geom.close();

        return LoadFromString(vertSource, geomSource, fragSource);
    }

    return LoadFromString(vertSource, "", fragSource);
}

bool Shader::LoadFromString(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
    return LoadFromString(vertexShaderSource, "", fragmentShaderSource);
}

bool Shader::LoadFromString(const std::string& vertexShaderSource, const std::string& geometryShaderSource, const std::string& fragmentShaderSource)
{
    if (m_shaderProgram)
    {
        glDeleteProgram(m_shaderProgram);
        m_shaderProgram = 0u;
    }

    m_shaderProgram = glCreateProgram();

    uint32 vert = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexChars = vertexShaderSource.c_str();
    glShaderSource(vert, 1, &vertexChars, NULL);
    glCompileShader(vert);
    if (!CheckShaderCompileErrors(vert, "Vertex"))
    {
        glDeleteShader(vert);
        glDeleteProgram(m_shaderProgram);
        m_shaderProgram = 0u;
        return false;
    }

    uint32 frag = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragChars = fragmentShaderSource.c_str();
    glShaderSource(frag, 1, &fragChars, NULL);
    glCompileShader(frag);
    if (!CheckShaderCompileErrors(frag, "Fragment"))
    {
        glDeleteShader(vert);
        glDeleteShader(frag);
        glDeleteProgram(m_shaderProgram);
        m_shaderProgram = 0u;
        return false;
    }

    uint32 geom = 0u;
    if (!geometryShaderSource.empty())
    {
        geom = glCreateShader(GL_GEOMETRY_SHADER);
        const char* geomChars = geometryShaderSource.c_str();
        glShaderSource(geom, 1, &geomChars, NULL);
        glCompileShader(geom);
        if (!CheckShaderCompileErrors(geom, "Geometry"))
        {
            glDeleteShader(vert);
            glDeleteShader(frag);
            glDeleteShader(geom);
            glDeleteProgram(m_shaderProgram);
            m_shaderProgram = 0u;
            return false;
        }
    }

    glAttachShader(m_shaderProgram, vert);
    glAttachShader(m_shaderProgram, frag);
    if (!geometryShaderSource.empty())
    {
        glAttachShader(m_shaderProgram, geom);
    }

    glLinkProgram(m_shaderProgram);
    if (!CheckProgramLinkErrors(m_shaderProgram))
    {
        glDeleteShader(vert);
        glDeleteShader(frag);
        if (!geometryShaderSource.empty())
        {
            glDeleteShader(geom);
        }
        glDeleteProgram(m_shaderProgram);
        m_shaderProgram = 0u;
        return false;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);
    if (!geometryShaderSource.empty())
    {
        glDeleteShader(geom);
    };

    return true;
}

void Shader::SetMatrix2f(uint32 location, Matrix2f& mat)
{
    Use();
    glUniformMatrix2fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMatrix2fSlow(const std::string& name, Matrix2f& mat)
{
    Use();
    glUniformMatrix2fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMatrix3f(uint32 location, Matrix3f& mat)
{
    Use();
    glUniformMatrix3fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMatrix3fSlow(const std::string& name, Matrix3f& mat)
{
    Use();
    glUniformMatrix3fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMatrix4f(uint32 location, Matrix4f& mat)
{
    Use();
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMatrix4fSlow(const std::string& name, Matrix4f& mat)
{
    Use();
    glUniformMatrix4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetVector2f(uint32 location, Vector2f & vec)
{
    Use();
    glUniform2fv(location, 1, &vec[0]);
}

void Shader::SetVector2fSlow(const std::string& name, Vector2f& vec)
{
    Use();
    glUniform2fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector2i(uint32 location, Vector2i& vec)
{
    Use();
    glUniform2iv(location, 1, &vec[0]);
}

void Shader::SetVector2iSlow(const std::string& name, Vector2i& vec)
{
    Use();
    glUniform2iv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector2u(uint32 location, Vector2u& vec)
{
    Use();
    glUniform2uiv(location, 1, &vec[0]);
}

void Shader::SetVector2uSlow(const std::string& name, Vector2u& vec)
{
    Use();
    glUniform2uiv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector3f(uint32 location, Vector3f & vec)
{
    Use();
    glUniform3fv(location, 1, &vec[0]);
}

void Shader::SetVector3fSlow(const std::string& name, Vector3f& vec)
{
    Use();
    glUniform3fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector3i(uint32 location, Vector3i& vec)
{
    Use();
    glUniform3iv(location, 1, &vec[0]);
}

void Shader::SetVector3iSlow(const std::string& name, Vector3i& vec)
{
    Use();
    glUniform3iv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector3u(uint32 location, Vector3u& vec)
{
    Use();
    glUniform3uiv(location, 1, &vec[0]);
}

void Shader::SetVector3uSlow(const std::string& name, Vector3u& vec)
{
    Use();
    glUniform3uiv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector4f(uint32 location, Vector4f & vec)
{
    Use();
    glUniform4fv(location, 1, &vec[0]);
}

void Shader::SetVector4fSlow(const std::string& name, Vector4f& vec)
{
    Use();
    glUniform4fv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector4i(uint32 location, Vector4i& vec)
{
    Use();
    glUniform4iv(location, 1, &vec[0]);
}

void Shader::SetVector4iSlow(const std::string& name, Vector4i& vec)
{
    Use();
    glUniform4iv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::SetVector4u(uint32 location, Vector4u& vec)
{
    Use();
    glUniform4uiv(location, 1, &vec[0]);
}

void Shader::SetVector4uSlow(const std::string& name, Vector4u& vec)
{
    Use();
    glUniform4uiv(glGetUniformLocation(m_shaderProgram, name.c_str()), 1, &vec[0]);
}

void Shader::Use()
{
    if (m_shaderProgram != m_activeShaderProgram)
    {
        glUseProgram(m_shaderProgram);
        m_activeShaderProgram = m_shaderProgram;
    }
}

bool Shader::CheckProgramLinkErrors(uint32 program)
{
    int32 success;
    char infoLog[1024];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        // @todo Add propper logger.
        std::cout << "Program ERROR: " << infoLog << "\n";
        return false;
    }

    return true;
}

bool Shader::CheckShaderCompileErrors(uint32 shader, const std::string& type)
{
    int32 success;
    char infoLog[1024];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        // @todo Add propper logger.
        std::cout << type << "ERROR: " << infoLog << "\n";
        return false;
    }

    return true;
}
} // namespace chill
