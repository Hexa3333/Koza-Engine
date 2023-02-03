workspace "Koza-Engine"
	architecture "x64"
	
	configurations { "Debug", "Release", "Dist"	}
	platforms { "Win64" }
	
	filter "platforms:Win64"
		defines "KOZA_PLATFORM_WINDOWS"
		system "windows"
	
	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		optimize "Full"


project "Koza-Engine"
	location "Engine"
	kind "ConsoleApp" -- SharedLib
	language "C++"
	cppdialect "C++20"
	ignoredefaultlibraries "MSVCRT"
	targetdir "bin/Koza-Engine(%{cfg.buildcfg})"
	files
	{
		"Engine/src/**.h",
		"Engine/src/**.cpp"
	}
	
	libdirs { "Engine/lib/GLEW", "Engine/lib/GLFW" }
	links { "opengl32", "glew32", "glfw3.lib" }
	
	includedirs
	{
		"Engine/include/GL",
		"Engine/include/GLFW",
		"Engine/include/glm",
		"Engine/include/stb",
		"Engine/include/spdlog/include"
	}
