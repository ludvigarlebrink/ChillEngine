#include "Window.hpp"

namespace chill
{
Window::Window()
    : m_pWindow(nullptr)
{
}

Window::Window(const std::string& title, int32 width, int32 height)
    : m_pWindow(nullptr)
{
    Create(title, width, height);
}

Window::~Window()
{
    if (m_pWindow)
    {
        SDL_DestroyWindow(m_pWindow);
    }
}

bool Window::Create(const std::string& title, int32 width, int32 height)
{
    m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!m_pWindow)
    {
        return false;
    }
    return true;
}
} // namespace chill
