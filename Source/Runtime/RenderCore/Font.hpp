#pragma once

#include "RenderCoreAPI.hpp"
#include "BaseTypes.hpp"
#include "Renderer.hpp"

#include <string>

namespace chill
{
class RENDER_CORE_API Font final
{
public:

    Font();

    ~Font();

    void LoadTTF(const std::string& filename, f32 fontSize);

private:

    f32 m_fontSize;
};
} // namespace chill
