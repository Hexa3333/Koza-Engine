#pragma once

#include <glew.h>
#include <glfw3.h>
#include <vector>

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
	
	unsigned int acc_width, acc_height;
private:
	void parseHintsGLFW(std::vector<int> Hints);

};