#include "Renderer.hpp"
#include "glad/glad.h"

namespace chill
{
void Renderer::EnableBlending(bool enable)
{
    if (enable)
    {
        glEnable(GL_BLEND);
        // TODO remove from here
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    else
    {
        glDisable(GL_BLEND);
    }
}
} // namespace chill
