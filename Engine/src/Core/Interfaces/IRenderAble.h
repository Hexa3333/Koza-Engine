#pragma once
#include "../Transform.h"
#include "../Shader.h"

namespace Koza_Core
{
	class IRenderAble
	{
	public:
		bool IsBeingRendered = true;
		void ToggleRender() { IsBeingRendered = !IsBeingRendered; }

		Transform transform;
		Shader* m_Shader;
		IRenderAble(Shader* shader) : m_Shader(shader) {}
		virtual void Render(Shader* shader) = 0;
		virtual void TickUniforms(Shader* shader)
		{
			glUniformMatrix4fv(glGetUniformLocation(shader->getShaderProgram(), "u_trans"), 1, GL_FALSE, glm::value_ptr(transform.m_transform));
		}
	
		IRenderAble() = delete;
		IRenderAble(const IRenderAble&) = delete;
		IRenderAble(IRenderAble&&) = delete;
	};
}