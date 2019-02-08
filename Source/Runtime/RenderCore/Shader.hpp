#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Math/MathFwd.hpp"

#include <string>

namespace chill
{
/**
 * @brief A shader program.
 */
class RENDER_CORE_API Shader
{
public:

    /**
     * @brief Creates a shader.
     */
    Shader();

    /**
     * @brief Destroys a shader.
     */
    virtual ~Shader();

    /**
     * @brief Get the location of a uniform.
     *
     * @param name Name of the uniform.
     * @return Location of a uniform.
     */
    uint32 getUniformLocation(const std::string& name) const;

    /**
     * @brief Load shader from a file.
     *
     * @param vertexShaderFilename Name and path to the vertex shader file.
     * @param fragmentShaderFilename Name and path to the fragment shader file.
     * @return True if everything went successfully. False if not.
     */
    bool load(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);

    /**
     * @brief Load shader from a file.
     *
     * @param vertexShaderFilename Name and path to the vertex shader file.
     * @param geometryShaderFilename Name and path to the geometry shader file.
     * @param fragmentShaderFilename Name and path to the fragment shader file.
     * @return True if everything went successfully. False if not.
     */
    bool load(const std::string& vertexShaderFilename, const std::string& geometryShaderFilename, const std::string& fragmentShaderFilename);

    /**
     * @brief Load shader from a string.
     *
     * @param vertexShaderSource Vertex shader source code.
     * @param fragmentShaderSource Fragment shader source code.
     * @return True if everything went successfully. False if not.
     */
    bool loadFromString(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

    /**
     * @brief Load shader from a string.
     *
     * @param vertexShaderSource Vertex shader source code.
     * @param geometryShaderSource Geometry shader source code.
     * @param fragmentShaderSource Fragment shader source code.
     * @return True if everything went successfully. False if not.
     */
    bool loadFromString(const std::string& vertexShaderSource, const std::string& geometryShaderSource, const std::string& fragmentShaderSource);

    /**
     * @brief Set a matrix uniform.
     *
     * @param location Location of uniform.
     * @param mat Matrix.
     */
    void setMatrix2f(uint32 location, Matrix2f& mat);

    /**
     * @brief Set a matrix uniform, slow.
     *
     * @param name Name of uniform.
     * @param mat Matrix.
     */
    void setMatrix2fSlow(const std::string& name, Matrix2f& mat);

    /**
     * @brief Set a matrix uniform.
     *
     * @param location Location of uniform.
     * @param mat Matrix.
     */
    void setMatrix3f(uint32 location, Matrix3f& mat);

    /**
     * @brief Set a matrix uniform, slow.
     *
     * @param name Name of uniform.
     * @param mat Matrix.
     */
    void setMatrix3fSlow(const std::string& name, Matrix3f& mat);

    /**
     * @brief Set a matrix uniform.
     *
     * @param location Location of uniform.
     * @param mat Matrix.
     */
    void setMatrix4f(uint32 location, Matrix4f& mat);

    /**
     * @brief Set a matrix uniform, slow.
     *
     * @param name Name of uniform.
     * @param mat Matrix.
     */
    void setMatrix4fSlow(const std::string& name, Matrix4f& mat);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector2f(uint32 location, Vector2f& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector2fSlow(const std::string& name, Vector2f& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector2i(uint32 location, Vector2i& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector2iSlow(const std::string& name, Vector2i& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector2u(uint32 location, Vector2u& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector2uSlow(const std::string& name, Vector2u& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector3f(uint32 location, Vector3f& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector3fSlow(const std::string& name, Vector3f& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector3i(uint32 location, Vector3i& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector3iSlow(const std::string& name, Vector3i& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector3u(uint32 location, Vector3u& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector3uSlow(const std::string& name, Vector3u& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector4f(uint32 location, Vector4f& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector4fSlow(const std::string& name, Vector4f& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector4i(uint32 location, Vector4i& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector4iSlow(const std::string& name, Vector4i& vec);

    /**
     * @brief Set a vector uniform.
     *
     * @param location Location of uniform.
     * @param vec Vector.
     */
    void setVector4u(uint32 location, Vector4u& vec);

    /**
     * @brief Set a vector uniform, slow.
     *
     * @param name Name of uniform.
     * @param vec Vector.
     */
    void setVector4uSlow(const std::string& name, Vector4u& vec);

    /**
     * @brief Use this shader.
     */
    void use();

private:

    static bool checkProgramLinkErrors(uint32 program);
   
    static bool checkShaderCompileErrors(uint32 shader, const std::string& type);

private:

    static uint32 m_activeShaderProgram;

    uint32 m_shaderProgram;
};
} // namespace chill

/**
 * @class Shader
 * @ingroup RenderCore
 */
