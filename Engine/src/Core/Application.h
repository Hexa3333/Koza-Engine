#pragma once
#include "Config.h"

#include <iostream>
#include <glfw3.h>
#include "Window.h"
#include "Renderer/Renderer.h"
#include "Log.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Koza_Core
{
	void Testing()
	{
		std::cout << "Test successful.\n";
	}

	class Application
	{
	private:
		Application() = default;
		Window* window;
		static Application& INST()
		{
			static Application _instance;
			return _instance;
		}
		static GLFWwindow* GetMainWindow()
		{
			return INST().window->getWindow();
		}

	public:


		static bool GetAppShouldRun()
		{
			return !glfwWindowShouldClose(GetMainWindow());
		}

		static void Init(const std::string& appName)
		{
			Log::Get().Init();
			INST().window = new Window(appName.c_str(), 720, 720);
			stbi_set_flip_vertically_on_load(true);
		}

		static void Run()
		{
			Renderer::MAIN().Run();

			INST().window->SwapBuffers();
			glfwPollEvents();
		}

		static void Kill()
		{
			Renderer::MAIN().Kill();
			glfwTerminate();
		}

	public:
		Application(const Application&) = delete;
	};
}