#include "Config.h"
#include "Mesh.h"

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

Mesh::Mesh(float* vertices, unsigned int* indices, int sizeVertices, int sizeIndices, GLenum drawType)
{
    this->sizeIndices = sizeIndices;
    this->view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * (sizeVertices / sizeof(float)), vertices, drawType);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * (sizeIndices / sizeof(int)), indices, drawType);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Hx_STRIDE, nullptr);
    glEnableVertexAttribArray(0); // 0 because (location 0), as i've noted 3 lines above

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, Hx_STRIDE, (void*)(3 * sizeof(float))); // Last argument is the offset (color is the fourth)
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Mesh::Render(Shader* pShader)
{
    pShader->Use();
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glDrawElements(GL_TRIANGLES, sizeIndices / 4 /* sizeof(int) = 4 */, GL_UNSIGNED_INT, 0);
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f) * 0.005f, glm::vec3(0.5f, 1.0f, 0.0f));
    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        glUniformMatrix4fv(glGetUniformLocation(pShader->getShaderProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Must send values
    glUniformMatrix4fv(glGetUniformLocation(pShader->getShaderProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(pShader->getShaderProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(pShader->getShaderProgram(), "view"), 1, GL_FALSE, glm::value_ptr(view));
}

void Mesh::Kill()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
