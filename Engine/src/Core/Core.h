#pragma once

#ifdef KZ_PLATFORM_WINDOWS

	#ifdef KZ_BUILD_DLL
		#define KOZA_API __declspec(dllexport)
	#else
		#define KOZA_API __declspec(dllimport)

	#endif

#else
	#error Koza currently only supports Windows 10/11

#endif