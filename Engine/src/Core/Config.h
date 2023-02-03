#pragma once

#ifdef KOZA_PLATFORM_WINDOWS
	#ifdef KOZA_BUILD_DLL
		#define KOZA_API __declspec(dllexport) 
	#else
		#define KOZA_API __declspec(dllimport)
	#endif // KOZA_BUILD_DLL


#else
	#error Koza Engine doesn't support this platform
#endif