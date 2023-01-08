#include "Window.h"
#include <iostream>

Window::Window(const char* Name, int w, int h)
{
    if (!glfwInit()) std::exit(-1);

    window = glfwCreateWindow(w, h, Name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::exit(-1);
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    }

    /* Make the window's context current */

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, false);
    parseHintsGLFW(Hints);
}



void Window::parseHintsGLFW(std::vector<int> Hints)
{
    for (int i = 0; i < Hints.size(); i += 2)
    {
        glfwWindowHint(Hints.at(i), Hints.at(i + 1));
    }
}
