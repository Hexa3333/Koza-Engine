#pragma once

#include <GL/glew.h>
#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh
{
protected:
	unsigned int VAO, VBO, EBO;
	GLsizei sizeIndices;

public:
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 720.f / 720.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::mat4(1.0f);


public:
	Mesh() = default;
	Mesh(float* vertices, unsigned int* indices, int sizeVertices, int sizeIndices, GLenum drawType=GL_STATIC_DRAW);
	
	void Render(Shader* pShader);
	void Kill();

};