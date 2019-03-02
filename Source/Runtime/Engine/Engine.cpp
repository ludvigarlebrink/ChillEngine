#include "Engine.hpp"
#include "ECSManager.hpp"
#include "RenderManager.hpp"
#include "UIManager.hpp"

#include "RenderWindow.hpp"
#include "SpriteRenderer.hpp"
#include "TextRenderer.hpp"

#include <iostream>

namespace chill
{
Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
    RenderWindow win("Test", 800, 600);

    SetUp();

    m_pUIManager->LoadUI("Data/UI/Main.ui");

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Event polling.
        }

        m_pUIManager->Render();

        win.SetClearColor(LinearColor(0.2f, 0.2f, 0.2f, 1.0f));
        win.Clear();

        m_pRenderManager->Render();

        win.Present();
    }

    TearDown();

    SDL_Quit();
}

void Engine::SetUp()
{
    m_pRenderManager = new RenderManager();
    m_pUIManager = new UIManager(m_pRenderManager);
}

void Engine::TearDown()
{
    delete m_pUIManager;
    m_pUIManager = nullptr;
}
} // namespace chill
