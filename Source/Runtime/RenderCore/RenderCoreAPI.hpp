#pragma once

#ifdef RENDER_CORE_API_DLL_EXPORT
#define RENDER_CORE_API __declspec(dllexport)
#else
#define RENDER_CORE_API __declspec(dllimport)
#endif

/**
 * @defgroup RenderCore Render Core
 *
 * Render Core works like a wrapper for OpenGL, so that OpenGL can be used
 * in a object oriented way.
 */
