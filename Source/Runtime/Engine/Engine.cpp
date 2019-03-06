#include "Engine.hpp"
#include "ECSManager.hpp"
#include "RenderManager.hpp"
#include "UIManager.hpp"

#include "RenderWindow.hpp"
#include "SpriteRenderer.hpp"
#include "TextRenderer.hpp"
#include "Terrain.hpp"
#include "Water.hpp"
#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    RenderWindow win("Test", 1280, 720);

    SetUp();

    m_pUIManager->LoadUI("Data/UI/Main.ui");
    Terrain* pTerrain = new Terrain();
    Water* pWater = new Water();
    Shader* pShader = new Shader();
    Shader* pWaterShader = new Shader();

    if (!pShader->Load("Data/Shaders/Terrain.vs.glsl", "Data/Shaders/Terrain.fs.glsl"))
    {
        std::cout << "Failed to load terrain shader.\n";
    }

    if (!pWaterShader->Load("Data/Shaders/Water.vs.glsl", "Data/Shaders/Water.fs.glsl"))
    {
        std::cout << "Failed to load water shader.\n";
    }

    pWater->Create(2048, 1024, 0.76f);

    pTerrain->LoadFromHeightMap("Data/TerrainHeight.bmp");

    glm::mat4 projection = glm::perspective(45.0f, 1280.0f / 720.0f, 1.0f, 100000.0f);

    glm::vec3 position = glm::vec3(400.0f, 200.0f, 200.0f);

    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    moveUp = true;
                    break;
                case SDLK_s:
                    moveDown = true;
                    break;
                case SDLK_a:
                    moveLeft = true;
                    break;
                case SDLK_d:
                    moveRight = true;
                    break;
                default:
                    break;
                }
                break;
            }
            case SDL_KEYUP:
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                    moveUp = false;
                    break;
                case SDLK_s:
                    moveDown = false;
                    break;
                case SDLK_a:
                    moveLeft = false;
                    break;
                case SDLK_d:
                    moveRight = false;
                    break;
                default:
                    break;
                }
                break;
            }
            case SDL_QUIT:
                break;

            default:
                break;
            }
        }

        if (moveUp)
        {
            position.z -= 10.0f;
        }
        else if (moveDown)
        {
            position.z += 10.0f;
        }  
        if (moveLeft)
        {
            position.x -= 10.0f;
        }
        else if (moveRight)
        {
            position.x += 10.0f;
        }

        win.EnableDepthTest(true);

        glm::mat4 view = glm::translate(glm::mat4(1.0f), position);
        view = glm::rotate(view, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        view = glm::rotate(view, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::rotate(view, glm::radians(240.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::scale(view, glm::vec3(1.0f, 1.0f, 1.0f));

        m_pUIManager->Render();

        win.SetClearColor(LinearColor(0.2f, 0.2f, 0.2f, 1.0f));
        win.Clear();

        pShader->Use();
        pShader->SetMatrix4fSlow("ViewProjection", projection * glm::inverse(view));

        pTerrain->Bind();
        pTerrain->Render();

        pWaterShader->Use();
        pWaterShader->SetMatrix4fSlow("ViewProjection", projection * glm::inverse(view));

        pWater->Bind();
        pWater->Render();

        win.EnableDepthTest(false);

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
