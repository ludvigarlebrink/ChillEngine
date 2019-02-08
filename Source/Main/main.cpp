#include "RenderWindow.hpp"
#include "glad/glad.h"

using namespace chill;

int main(int argc, char* argv[])
{
    RenderWindow win("Test", 800, 600);

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Event polling.
        }

        win.setClearColor(Color::RED);
        win.clear();

        win.present();
    }

    SDL_Quit();

    return 0;
}
