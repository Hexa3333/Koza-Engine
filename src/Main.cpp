
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

    float pos[] = {
        //    VERTICES            UV
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle
    };

    Sprite* spriteParan1 = new Sprite("res/paran1.png");
    Gameobject* portakal = new Gameobject(new Sprite("res/paran1.png"));

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