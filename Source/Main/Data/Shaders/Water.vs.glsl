#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 ViewProjection = mat4(1.0);

void main()
{
    gl_Position = ViewProjection * vec4(position, 1.0);
}
