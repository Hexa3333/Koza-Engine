#pragma once

#include <glew.h>
#include <glfw3.h>
#include <vector>

namespace KozaCore
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

		Window(const char* Name, int w, int h, int Properties=NULL);
		void SwapBuffers();
		void Clear();
	
		GLFWwindow* getWindow() { return window; }

	private:
		void parseProperties(int Properties);
		void parseHintsGLFW(std::vector<int>& Hints);
	};

	// PROPERTIES
	constexpr uint8_t WINDOW_FULLSCREEN = 0x01;
	constexpr uint8_t WINDOW_NORESIZE = 0x02;

}