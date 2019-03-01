#include "RenderWindow.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "Math/Math.hpp"
#include "SpriteRenderer.hpp"
#include "Texture.hpp"
#include "Font.hpp"
#include "TextRenderer.hpp"
#include "UIManager.hpp"
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

    Font* font = new Font();
    font->LoadTTF("Data/arial.ttf", 18);

    TextRenderer textRenderer;

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Event polling.
        }

        spriteRenderer.Submit(texture, Recti(0, 0, 256, 256));
        textRenderer.Submit("Very good engine\nArchitecture", font, Vector2f(0.0f, 500.0f), LinearColor(0.4f, 1.0f, 0.3f, 1.0f));

        win.SetClearColor(LinearColor(1.0f, 0, 0, 1.0f));
        win.Clear();

        spriteRenderer.Render();
        textRenderer.Render();

        win.Present();
    }

    SDL_Quit();

    return 0;
}
