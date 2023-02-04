#include "Window.h"
#include <iostream>
#include <stdarg.h>

using namespace Koza_Core;

Window::Window(const char* Name, int w, int h, int numOfProperties, ...)
{
    if (!glfwInit()) std::exit(-1);
    va_list args;
    va_start(args, numOfProperties);

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

    va_end(args);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(this->window);
}

void Window::parseHintsGLFW(std::vector<int> Hints)
{
    for (int i = 0; i < Hints.size(); i += 2)
    {
        glfwWindowHint(Hints.at(i), Hints.at(i + 1));
    }
}