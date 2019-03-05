#version 450 core

out vec4 fragColor;

in vec3 vsPosition;
in vec3 vsNormal;
in vec2 vsTexCoords1;
in vec2 vsTexCoords2; 

void main()
{
    vec3 dir = normalize(vec3(0.0, -0.9, 1.0));
    float intensity = dot(normalize(vsNormal), dir);
    vec3 col = vec3(0.86, 0.89, 0.54) * intensity;
    fragColor = vec4(clamp(col, vec3(0.0), vec3(1.0)), 1.0);
}
