#include "Window.hpp"

using namespace chill;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Window win("Test", 800, 600);

    while (true)
    {
        // loop
    }

    SDL_Quit();

    return 0;
}
