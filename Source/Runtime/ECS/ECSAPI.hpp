#pragma once

#ifdef ECS_API_DLL_EXPORT
#define ECS_API __declspec(dllexport)
#else
#define ECS_API __declspec(dllimport)
#endif

/**
 * @defgroup ECS Entity Component System
 */
