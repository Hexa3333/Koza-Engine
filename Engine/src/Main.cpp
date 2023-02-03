#include <glew.h>
#include <glfw3.h>

#include <iostream>
#include <algorithm>
#include <format>

#include "Core/Application.h"
#include "Core/Shader.h"
#include "Core/Sprite.h"
#include "Core/Gameobject.h"
#include "Core/Debugging/Log.h"

using namespace Koza_Core;

// TODO:
// Default shader which takes position data
// and displays them in a missing texture format for
// gizmos and stuff

int main(void)
{
    Application::Init(std::format("Koza Engine - {} | {}", __DATE__, __TIME__));
    
    Shader* basicShader = new Shader("../res/Shaders/myVert.shader", "../res/Shaders/myFrag.shader");

    while (Application::GetAppShouldRun())
    {
        Application::Run();
    }

    delete basicShader;

    Application::Kill();
    return 0;
}