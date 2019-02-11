#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"

namespace chill
{
/**
 * @brief A vertex array.
 */
class RENDER_CORE_API VertexArray
{
public:

    /**
     * @brief Mode for which a vertex array will be optimized for.
     */
    enum class Mode
    {
        DYNAMIC_DRAW,
        STATIC_DRAW
    };

    enum class Type
    {
        F32,
        INT32,
        VECTOR2F,
        VECTOR3F,
        VECTOR4F
    };

public:

    /**
     * @brief Creates a vertex array.
     */
    VertexArray();

    /**
     * @brief Destroys a vertex array.
     */
    virtual ~VertexArray();

    /**
     * @brief Bind this vertex array.
     */
    void Bind();

    /**
     * @brief Enables an attribute.
     *
     * @param index Index of attribute to enable.
     */
    void EnableAttrib(int32 index);
    
    /**
     * @brief This class will load (or copy) data from the ram to the v-ram.
     *
     * @param pVertexData
     * @param vertexSize
     * @param vertexCount
     * @param pElementData
     * @param elementCount
     */
    void Load(void* pVertexData, int32 vertexSize, int32 vertexCount, uint32* pElementData, int32 elementCount);

    /**
     * @brief Maps the array buffer for reading.
     *
     * @return Void pointer to array buffer.
     *
     * Call unmap once done reading.
     */
    void* MapForReading();

    /**
     * @brief Maps the array buffer for reading.
     *
     * @return Void pointer to array buffer.
     *
     * Call unmap once done writing.
     *
     * Mapping a buffer can be useful for things such as batch rendering. Let's look at how
     * we can do that, by creating a very simple batch renderer. First we need to have a
     * a defintion for our sprite.
     *
     * @code
     * // For instance we can define a sprite vertex.
     * struct SpriteVertex
     * {
     *     // Position of the sprite.
     *     Vector2f sprite;
     *     // The sprite's texture coordinates in UV-space.
     *     Vector2f textureCoords;
     * }
     * @endcode
     *
     * Next let's look at the code during this update function.
     *
     * @code
     * SpriteVertex* pSpriteVertices = static_cast<SpriteVertex*>(vertexArray.mapForWriting());
     *
     * // Lets say we have a sprite class.
     * for (auto sprite : sprites)
     * {
     *     // This will move the pointer by sizeof(SpriteVertex).
     *     ++pSriteVerteices;
     * }
     *
     * // Once we are done mapping we have to use the unmap function.
     * 
     * @endcode
     *
     * And there we have it! A simple batch renderer.
     */
    void* MapForWriting();

    /**
     * @brief Render this vertex array.
     */
    void Render();

    /**
     * @brief Render this vertex array.
     */
    void Render(int32 count, int32 start);

    /**
     * @brief Set a pointer to an attribute in the vertex array.
     *
     * @param index
     * @param type
     * @param offset
     */s
    void SetAttribPtr(int32 index, Type type, int32 offset);

    /**
     * @brief Unmaps the buffer.
     *
     * Call this function when done reading or writing to the buffer.
     */
    void Unmap();

private:

    uint32 m_vao;
    uint32 m_vbo;
    uint32 m_ebo;
    int32 m_vertexCount;
    int32 m_vertexSize;
    int32 m_elementCount;
};
} // namespace chill

/**
 * @class VertexArray
 * @ingroup RenderCore
 *
 * @code
 * struct Vertex
 * {
 *     Vector3f position;
 *     LinearColor color;
 * };
 * @endcode
 */