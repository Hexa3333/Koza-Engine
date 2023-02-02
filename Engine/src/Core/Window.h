#pragma once

#include <glew.h>
#include <glfw3.h>
#include <vector>

namespace Kz_Core
{
	struct Window
	{
		private:
			GLFWwindow* window;

			std::vector<int> Hints = {
				GLFW_CONTEXT_VERSION_MAJOR, 4,
				GLFW_CONTEXT_VERSION_MINOR, 0,
				GLFW_OPENGL_CORE_PROFILE, GLFW_TRUE};

		public:

			Window(const char* Name, int w, int h);
	
			GLFWwindow* getWindow() { return window; }
			static bool shouldRun(GLFWwindow* win) { return !glfwWindowShouldClose(win); }
			template< typename T >
			static void Clear(T param);

			unsigned int acc_width, acc_height;
		private:
			void parseHintsGLFW(std::vector<int> Hints);
	};

}


#define WINDOW_SHOULD_KEEP_RUNNING(...) !glfwWindowShouldClose(__VA_ARGS__)