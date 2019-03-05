#version 450 core

out vec4 fragColor;

void main()
{
    fragColor = vec4(vec3(0.39, 0.45, 0.58) * 0.6, 1.0);
}
