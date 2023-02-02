#include <glew.h>
#include <glfw3.h>

#include <iostream>
#include <algorithm>
#include <format>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Core/Application.h"
#include "Core/Renderer.h"
#include "Core/Shader.h"
#include "Core/Sprite.h"
#include "Core/Gameobject.h"

using namespace Kz_Core;

// TODO:
// Default shader which takes position data
// and displays them in a missing texture format for
// gizmos and stuff

int main(void)
{
    Application::Init(std::format("Koza Engine - {} | {}", __DATE__, __TIME__));

    Shader* basicShader = new Shader("res/Shaders/myVert.shader", "res/Shaders/myFrag.shader");
    
    std::unique_ptr<Gameobject> grill = std::make_unique<Gameobject>(new Sprite("res/paran1.png"), basicShader);
    std::unique_ptr<Gameobject> orange = std::make_unique<Gameobject>(new Sprite("res/paran2.png"), basicShader);


    while (!glfwWindowShouldClose(Application::GetMainWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_ESCAPE)) goto exit;

        Application::Run();
    }

exit:
    delete basicShader;

    Application::Kill();
    return 0;
}