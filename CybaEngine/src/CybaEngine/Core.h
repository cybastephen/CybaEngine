#pragma once

#ifdef CY_PLATFORM_WINDOWS
	#ifdef CY_BUILD_DLL
		#define CYBA_API __declspec(dllexport)
	#else
		#define CYBA_API __declspec(dllimport)
	#endif
#else
	#error CybaEngine only support Windows;
#endif