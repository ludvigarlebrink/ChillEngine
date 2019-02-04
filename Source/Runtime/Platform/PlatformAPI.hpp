#pragma once

#ifdef PLATFORM_API_DLL_EXPORT
#define PLATFORM_API __declspec(dllexport)
#else
#define PLATFORM_API __declspec(dllimport)
#endif
