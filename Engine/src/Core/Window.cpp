#include "Window.h"
#include <iostream>
#include <stdarg.h>

using namespace KozaCore;

Window::Window(const char* Name, int w, int h, int Properties)
{
    if (!glfwInit()) std::exit(-1);

    if (Properties & WINDOW_FULLSCREEN)
        window = glfwCreateWindow(w, h, Name, glfwGetPrimaryMonitor(), NULL);

    else window = glfwCreateWindow(w, h, Name, NULL, NULL);

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

    parseProperties(Properties);
    parseHintsGLFW(Hints);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(this->window);
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::parseProperties(int Props)
{
    switch (Props)
    {
        case WINDOW_NORESIZE:
            glfwSetWindowAttrib(window, GLFW_RESIZABLE, false);
            break;

    }
}

void Window::parseHintsGLFW(std::vector<int> Hints)
{
    for (int i = 0; i < Hints.size(); i += 2)
    {
        glfwWindowHint(Hints.at(i), Hints.at(i + 1));
    }
}