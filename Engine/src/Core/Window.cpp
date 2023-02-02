#include "Window.h"
#include <iostream>

using namespace Kz_Core;

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

template<typename T>
inline void Window::Clear(T param)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::parseHintsGLFW(std::vector<int> Hints)
{
    for (int i = 0; i < Hints.size(); i += 2)
    {
        glfwWindowHint(Hints.at(i), Hints.at(i + 1));
    }
}