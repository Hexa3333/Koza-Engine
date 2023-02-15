#include "Gameobject.h"

#include <iostream>
#include <string>
#include "Renderer/Renderer.h"
#include <glfw3.h>

/*

*   For 2D usage of sprites, the stride has been set to 5.
*   Therefore there is no color value and if you load vertices that
*   contain color values it won't work the way you'd expect.    

*   And to remodify:
* 
*   - Modify the Stride
*   - Send the view matrix

*/

namespace Koza_Core
{
    static float defaultSpriteVertices[32] = {
        //    VERTICES          // TEXTURE
         1.0f,  1.0f, 0.0f,		1.0f, 1.0f,      // top right
         1.0f, -1.0f, 0.0f,		1.0f, 0.0f,      // bottom right
        -1.0f, -1.0f, 0.0f,		0.0f, 0.0f,      // bottom left
        -1.0f, 1.0f, 0.0f,		0.0f, 1.0f        // top left
    };
    static unsigned int defaultSpriteIndices[6] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    static GLsizei Stride = (5 * sizeof(float));

    Gameobject::Gameobject(Sprite* sprite, Shader* shader, GLenum drawType)
        : sizeIndices(sizeof(defaultSpriteIndices)), sprite(*sprite), IRenderAble(shader)
    {
        Renderer::MAIN().Entities.push_back(this);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(defaultSpriteVertices[0]) * (sizeof(defaultSpriteVertices) / sizeof(float)), defaultSpriteVertices, drawType);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(defaultSpriteIndices[0]) * (sizeof(defaultSpriteIndices) / sizeof(int)), defaultSpriteIndices, drawType);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Stride, nullptr);
        glEnableVertexAttribArray(0); // 0 because (location 0), as i've noted 3 lines above

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, Stride, (void*)(3 * sizeof(float))); // Last argument is the offset (color is the fourth)
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }

    void Gameobject::Render(Shader* shader)
    {
        shader->Use();
        sprite.Bind();

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, sizeIndices / 4 /*sizeof(int) == 4*/, GL_UNSIGNED_INT, 0);

        TickUniforms(shader);
    }

    Gameobject::~Gameobject()
    {
        this->IsBeingRendered = false;

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }

    void Gameobject::TickUniforms(Shader* pShader)
    {
        glUniformMatrix4fv(glGetUniformLocation(pShader->getShaderProgram(), "trans"), 1, GL_FALSE, glm::value_ptr(transform.transform));
    }
}


