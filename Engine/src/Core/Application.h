#pragma once
#include "Core.h"

#include <iostream>
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include <stb_image.h>

namespace Kz_Core
{

	class KOZA_API Application
	{
	private:
		Application() = default;

		Window* window;
	public:
		static Application& Instance()
		{
			static Application _instance;
			return _instance;
		}

		static GLFWwindow* GetMainWindow()
		{
			return Instance().window->getWindow();
		}

		static void Init(const std::string& appName)
		{
			Instance().window = new Window(appName.c_str(), 720, 720);
			stbi_set_flip_vertically_on_load(true);
		}

		static void Run()
		{
			glClear(GL_COLOR_BUFFER_BIT);
			Renderer::MAIN().Run();

			glfwSwapBuffers(Application::GetMainWindow());
			glfwPollEvents();
		}

		static void Kill()
		{
			glfwTerminate();
		}

	public:
		Application(const Application&) = delete;
	};

}
