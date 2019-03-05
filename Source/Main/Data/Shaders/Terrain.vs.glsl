#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords1;
layout (location = 3) in vec2 texCoords2;

out vec3 vsPosition;
out vec3 vsNormal;
out vec2 vsTexCoords1;
out vec2 vsTexCoords2;

uniform mat4 ViewProjection = mat4(1.0);

void main()
{
    vsPosition = position;
    gl_Position = ViewProjection * vec4(position, 1.0);
    vsNormal = normal;
    vsTexCoords1 = texCoords1;
    vsTexCoords2 = vsTexCoords2;
}
