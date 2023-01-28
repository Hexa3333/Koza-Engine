#pragma once
#include <iostream>
#include "Window.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

class Application
{
private:
	Application() = default;

	Window* window;
public:
	static Application& INST()
	{
		static Application _instance;
		return _instance;
	}

	static GLFWwindow* GetMainWindow()
	{
		return INST().window->getWindow();
	}

	static void Init(const std::string& appName)
	{
		INST().window = new Window(appName.c_str(), 720, 720);
		stbi_set_flip_vertically_on_load(true);
	}


public:
	Application(const Application&) = delete;
};

