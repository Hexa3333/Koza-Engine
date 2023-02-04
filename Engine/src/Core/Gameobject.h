#pragma once

#include "glew.h"
#include "Shader.h"
#include "Sprite.h"
#include "Interfaces/IRenderAble.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Globals.h"

using namespace Koza_Globals;

namespace Koza_Core
{
	class Gameobject : public IRenderAble
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
		~Gameobject();
	
		
		void ToggleRender() override;
		void Render(Shader* shader) override;
	private:
		void TickUniforms(Shader* pShader);

	};

}