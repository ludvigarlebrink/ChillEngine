#include "RenderWindow.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "Math/Math.hpp"
#include "SpriteRenderer.hpp"
#include "Texture.hpp"
#include <iostream>

using namespace chill;

int main(int argc, char* argv[])
{
    RenderWindow win("Test", 800, 600);
    SpriteRenderer spriteRenderer;
    Texture* texture = new Texture();
    if (!texture->LoadFromFile("Data/Test.png"))
    {
        std::cout << "Could not find image\n";
    }

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Event polling.
        }

        spriteRenderer.Begin();
        spriteRenderer.Submit(texture, Recti(0, 0, 256, 256));
        spriteRenderer.End();

        win.SetClearColor(LinearColor(1.0f, 0, 0, 1.0f));
        win.Clear();

        spriteRenderer.Render();

        win.Present();
    }

    SDL_Quit();

    return 0;
}
