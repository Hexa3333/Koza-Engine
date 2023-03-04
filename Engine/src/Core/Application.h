#pragma once
#include "Config.h"

#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include "Window.h"
#include "Renderer/Renderer.h"
#include "stb_image.h"
#include "Game.h"
#include "Time.h"

namespace Koza_Core
{

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

	public:

		static GLFWwindow* GetMainWindow()
		{
			return INST().window->getWindow();
		}

		static bool GetAppShouldRun()
		{
			return !glfwWindowShouldClose(GetMainWindow());
		}

		static void Init(const std::string& appName, uint16_t WX, uint16_t WY)
		{
			INST().window = new Window(appName.c_str(), WX, WY);

			stbi_set_flip_vertically_on_load(true);

			Renderer::MAIN().Init();
			Game::MStart();
		}

		static void Run()
		{
			Time::Calculate();
			Game::MUpdate();

			INST().window->Clear();
			Renderer::MAIN().Run();
			INST().window->SwapBuffers();
			glfwPollEvents();
		}

		static void Kill()
		{
			glfwTerminate();
			Renderer::MAIN().Kill();
			Shader::Kill();
		}
	};
}