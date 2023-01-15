
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <algorithm>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Config.h"
#include "Core/Window.h"
#include "Core/Shader.h"
#include "Core/Sprite.h"
#include "Core/Gameobject.h"
#include "Core/Sprite.h"

int main(void)
{
    Window window("Koza Engine", 720, 720);
    stbi_set_flip_vertically_on_load(true);

    Shader* basicShader = new Shader();
    basicShader->CreateFromFile("res/Shaders/defaultV.shader", "res/Shaders/defaultF.shader");

    Gameobject* portakal = new Gameobject(new Sprite("res/paran2.png"));
    
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if (glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE)) break;

        portakal->Render(basicShader);


        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }

    delete basicShader;

    glfwTerminate();
    return 0;
}