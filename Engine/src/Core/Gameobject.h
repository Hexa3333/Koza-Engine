#pragma once

#include "glew.h"
#include "../Components/Shader.h"
#include "../Components/Sprite.h"
#include "Interfaces/IRenderAble.h"
#include "../Components/Transform.h"
#include "Globals.h"
#include <memory>

using namespace KozaCore;
using namespace std;

namespace KozaCore
{
	class Gameobject : public IRenderAble
	{
	private:
		unsigned int VAO, VBO, EBO;
		GLsizei sizeIndices;
		shared_ptr<Sprite> m_Sprite;
		shared_ptr<Shader> m_Shader;

	public:

		Gameobject() = default;

		Gameobject(Sprite* sprite, 
			Shader* shader = new Shader(DEFAULT_VERTEX_SHADER, DEFAULT_FRAGMENT_SHADER),
			GLenum drawType = GL_STATIC_DRAW);

		~Gameobject();
		
		virtual void Render() override;
	};

}