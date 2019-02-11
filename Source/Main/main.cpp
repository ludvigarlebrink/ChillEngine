#include "RenderWindow.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "Math/Math.hpp"
#include <iostream>

using namespace chill;

struct Vertex
{
    Vector2f position;
};

const char *vertexShaderSource = "#version 450 core\n"
"layout (location = 0) in vec2 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 450 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0, 0.5, 1.0, 1.0);\n"
"}\n\0";

int main(int argc, char* argv[])
{
    RenderWindow win("Test", 800, 600);

    Vertex v[4];
    v[0].position = { 0.5f, 0.5f };
    v[1].position = { 0.5f, -0.5f };
    v[2].position = { -0.5f, -0.5f };
    v[3].position = { -0.5f, 0.5f };

    uint32 indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    Shader s;
    if (!s.LoadFromString(vertexShaderSource, fragmentShaderSource))
    {
        std::cout << "something went wrong\n";
    }

    VertexArray a;
    a.Load(v, sizeof(Vertex), 4, indices, 6);
    a.SetAttribPtr(0, VertexArray::Type::VECTOR2F, 0);
    a.EnableAttrib(0);

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Event polling.
        }

        win.SetClearColor(LinearColor(1.0f, 0, 0, 1.0f));
        win.Clear();
        s.Use();
        a.Bind();
        a.Render();
        win.Present();
    }

    SDL_Quit();

    return 0;
}
