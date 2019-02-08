#include "RenderWindow.hpp"
#include "glad/glad.h"

namespace chill
{
RenderWindow::RenderWindow()
    : m_pWindow(nullptr)
{
}

RenderWindow::RenderWindow(const std::string& title, int32 width, int32 height)
    : m_pWindow(nullptr)
{
    create(title, width, height);
}

RenderWindow::~RenderWindow()
{
    if (m_context)
    {
        SDL_GL_DeleteContext(m_context);
    }

    if (m_pWindow)
    {
        SDL_DestroyWindow(m_pWindow);
    }
}

void RenderWindow::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool RenderWindow::create(const std::string& title, int32 width, int32 height)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    if (!m_pWindow)
    {
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    m_context = SDL_GL_CreateContext(m_pWindow);
    if (!m_context)
    {
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        return false;
    }

    return true;
}

void RenderWindow::setClearColor(const Color& clearColor)
{
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
}

void RenderWindow::present()
{
    SDL_GL_SwapWindow(m_pWindow);
}
} // namespace chill
