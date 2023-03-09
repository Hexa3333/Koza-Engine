workspace "Koza-Engine"
	architecture "x64"
	
	configurations { "Debug", "Release", "Dist"	}
	platforms { "Win64", "Debian" }
	
	filter "platforms:Win64"
		defines "KOZA_PLATFORM_WINDOWS"
		system "windows"

	filter "platforms:Debian"
		defines "KOZA_PLATFORM_DEBIAN"
		system "linux"

	

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		optimize "Full"

INCLUDES = { 
	"Engine/include/GL",
	"Engine/include/GLFW",
	"Engine/include/glm",
	"Engine/include/stb",
	"Engine/include/spdlog/include"
	}

project "Koza-Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	ignoredefaultlibraries "MSVCRT"
	files
	{
		"Engine/src/**.h",
		"Engine/src/**.cpp"
	}


	filter "platforms:Win64"
		libdirs { "Engine/lib/GLEW", "Engine/lib/GLFW" }
		links { "opengl32", "glew32", "glfw3" }
	
	includedirs { INCLUDES }
	

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	ignoredefaultlibraries "MSVCRT"
	targetdir "Game/bin/"
	files
	{
		"Game/src/**.cpp",
		"Game/src/**.h"
	}
	filter "platforms:Win64"
		libdirs { "Engine/lib/GLEW", "Engine/lib/GLFW" }
		links { "opengl32", "glew32", "glfw3", "Koza-Engine" }

	includedirs{ INCLUDES, "Engine/src/UserIncludes" }