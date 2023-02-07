#pragma once

#include "glew.h"
#include "Shader.h"
#include "Sprite.h"
#include "Interfaces/IRenderAble.h"
#include "Transform.h"
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
		Transform transform;

		Gameobject() = default;
		Gameobject(Sprite* sprite, Shader* shader = new Shader(DEFAULT_VERTEX_SHADER, DEFAULT_FRAGMENT_SHADER), GLenum drawType = GL_STATIC_DRAW);
		~Gameobject();
		
		virtual void Render(Shader* shader) override;

	private:
		virtual void TickUniforms(Shader* pShader) override;
	};

}