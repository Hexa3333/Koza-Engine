#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include "Sprite.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Gameobject
{
private:
	unsigned int VAO, VBO, EBO;
	GLsizei sizeIndices;
	Sprite& sprite;


public:
	glm::mat4 model = glm::mat4(1.0f);

public:
	Gameobject() = default;
	//Gameobject(float* vertices, unsigned int* indices, int sizeVertices, int sizeIndices, GLenum drawType=GL_STATIC_DRAW);
	
	// For 2D game objects
	Gameobject(Sprite* pSprite, GLenum drawType=GL_STATIC_DRAW);
	
	void Render(Shader* pShader);
	void Kill();

private:
	void TickUniforms(Shader* pShader);

};