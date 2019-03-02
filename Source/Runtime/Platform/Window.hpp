#pragma once

#include "PlatformAPI.hpp"
#include "BaseTypes.hpp"

#include <SDL/SDL.h>
#include <string>

namespace chill
{
/**
 * @brief A simple window.
 */
class PLATFORM_API Window
{
public:

    /**
     * @brief Creates a window.
     */
    Window();

    /**
     * @brief Creates a window.
     *
     * @param title Title of this window.
     * @param width Width of this window.
     * @param height Height of this window.
     */
    Window(const std::string& title, int32 width, int32 height);

    /**
     * @brief Destroys a window.
     */
    virtual ~Window();

    /**
     * @brief Creates a window.
     *
     * @param title Title of this window.
     * @param width Width of this window.
     * @param height Height of this window.
     * @return True if successfully created. False if not.
     */
    bool Create(const std::string& title, int32 width, int32 height);

private:

    SDL_Window* m_pWindow;
};
} // namespace chill

/**
 * @class chill::Window
 * @ingroup Platform
 * @author Ludvig Arlebrink
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