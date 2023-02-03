workspace "Koza-Engine"
	architecture "x64"
	configurations
	{
		Debug,
		Release,
		Dist
	}
	
	location "build"

project "Koza-Engine"
	kind "SharedLib"
	language "C++"
	targetdir "bin/Koza-Engine_%{cfg.buildcfg}"

	files
	{
		"Engine/src/**.h",
		"Engine/src/**.cpp"
	}

	filter "configurations:Debug"
		defines { "Debug" }
		symbols on

	filter "configurations:Release"
		defines { "Release" }
		optimize on

	defines
	{
		KOZA_PLATFORM_WINDOWS,
		KOZA_BUILD_DLL
	}
	libdirs
	{
		"Engine/lib"
	}


project "Game"
	kind "WindowedApp"
	language "C++"
	files
	{
		"Game/src/**.h",
		"Game/src/**.cpp"
	}
	links
	{
		"Koza-Engine"
	}
	defines
	{
		KOZA_PLATFORM_WINDOWS
	}