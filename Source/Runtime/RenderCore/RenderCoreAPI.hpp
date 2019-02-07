#pragma once

#ifdef RENDER_CORE_API_DLL_EXPORT
#define RENDER_CORE_API __declspec(dllexport)
#else
#define RENDER_CORE_API __declspec(dllimport)
#endif

/**
 * @defgroup Platform
 *
 * A collection of platform specific features.
 */
