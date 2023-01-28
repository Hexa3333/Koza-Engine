#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include "Sprite.h"
#include "ARenderAble.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Globals.h"

using namespace GLOBAL;

class Gameobject : public ARenderAble
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
	
	Gameobject(Sprite* sprite, Shader* shader = new Shader(DEFAULT_VERTEX_SHADER, DEFAULT_FRAGMENT_SHADER), GLenum drawType = GL_STATIC_DRAW);
	

	void Render(Shader* shader) override;
	~Gameobject();

private:
	void TickUniforms(Shader* pShader);

};