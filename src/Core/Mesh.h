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
	
	glm::vec3 cubePositions[11] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

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