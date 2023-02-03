#include <glew.h>
#include <glfw3.h>

#include <iostream>
#include <algorithm>
#include <format>

#include "Core/Application.h"
#include "Core/Shader.h"
#include "Core/Sprite.h"
#include "Core/Gameobject.h"

#include "Core/Log.h"

using namespace Koza_Core;

// TODO:
// Default shader which takes position data
// and displays them in a missing texture format for
// gizmos and stuff

int main(void)
{
    Application::Init(std::format("Koza Engine - {} | {}", __DATE__, __TIME__));
    
    Shader* basicShader = new Shader("../res/Shaders/myVert.shader", "../res/Shaders/myFrag.shader");

    std::unique_ptr<Gameobject> grill = std::make_unique<Gameobject>(new Sprite("../res/paran1.png"), basicShader);
    std::unique_ptr<Gameobject> orange = std::make_unique<Gameobject>(new Sprite("../res/paran2.png"), basicShader);


    while (Application::GetAppShouldRun())
    {
        Application::Run();
    }

exit:
    delete basicShader;

    Application::Kill();
    return 0;
}