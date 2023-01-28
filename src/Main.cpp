#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <algorithm>
#include <format>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Application.h"
#include "Core/Renderer.h"
#include "Core/Shader.h"
#include "Core/Sprite.h"
#include "Core/Gameobject.h"
#include "Core/Sprite.h"

// TODO:
// Default shader which takes position data
// and displays them in a missing texture format for
// gizmos and stuff

int main(void)
{
    Application::Init(std::format("Koza Engine - {} | {}", __DATE__, __TIME__));

    Shader* basicShader = new Shader("res/Shaders/myVert.shader", "res/Shaders/myFrag.shader");
    
    Gameobject* animeGirl = new Gameobject(new Sprite("res/paran1.png"));
    Gameobject* orange = new Gameobject(new Sprite("res/paran2.png"));

    while (!glfwWindowShouldClose(Application::GetMainWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_ESCAPE)) break;
        if (glfwGetKey(Application::GetMainWindow(), GLFW_KEY_SPACE))
        {
            Renderer::INST().Entities.pop_back();
        }

        Renderer::INST().Run();

        glfwSwapBuffers(Application::GetMainWindow());
        glfwPollEvents();
    }

    delete basicShader;
    //delete portakal;

    glfwTerminate();
    return 0;
}