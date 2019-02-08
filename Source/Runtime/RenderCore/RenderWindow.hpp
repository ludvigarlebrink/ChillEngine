#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Math/Color.hpp"

#include <SDL/SDL.h>
#include <string>

namespace chill
{
/**
 * @brief A window used for rendering.
 */
class RENDER_CORE_API RenderWindow
{
public:

    /**
     * @brief Creates a render window.
     */
    RenderWindow();

    /**
     * @brief Creates a render window.
     *
     * @param title Title of this window.
     * @param width Width of this window.
     * @param height Height of this window.
     */
    RenderWindow(const std::string& title, int32 width, int32 height);

    /**
     * @brief Destroys a render window.
     */
    virtual ~RenderWindow();

    /**
     * @brief Clears the backbuffer.
     */
    void clear();

    /**
     * @brief Creates a window.
     *
     * @param title Title of this window.
     * @param width Width of this window.
     * @param height Height of this window.
     * @return True if successfully created. False if not.
     */
    bool create(const std::string& title, int32 width, int32 height);

    /**
     * @brief Set the color the backbuffer will be cleared with.
     *
     * @param clearColor Color the backbuffer will be cleared with.
     */
    void setClearColor(const Color& clearColor);

    /**
     * @brief Swap the front with the backbuffer.
     */
    void present();

private:

    SDL_Window* m_pWindow;
    SDL_GLContext m_context;
};
} // namespace chill

/**
 * @class chill::RenderWindow
 * @ingroup RenderCore
 *
 * @code
 * // Create a window.
 * Window win();
 *
 * // Create the window with error handling.
 * if (win.create() == false)
 * {
 *     // Window was not successfully create.
 *     return false;
 * }
 * @endcode
 */
