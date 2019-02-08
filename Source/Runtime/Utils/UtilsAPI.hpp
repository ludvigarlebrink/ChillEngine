#pragma once

#ifdef UTILS_API_DLL_EXPORT
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

/**
 * @defgroup Utils
 *
 * A collection of utility features.
 *
 * @addtogroup Math
 * @ingroup Utils
 */
