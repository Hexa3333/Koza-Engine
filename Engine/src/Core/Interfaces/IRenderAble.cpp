#include "IRenderAble.h"
#include "../Renderer/Renderer.h"

namespace KozaCore
{

	void IRenderAble::TickUniforms(Shader* shader)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_Shader->getShaderProgram(), "u_model"), 1, GL_FALSE, glm::value_ptr(transform.m_transform));
		glUniformMatrix4fv(glGetUniformLocation(m_Shader->getShaderProgram(), "u_projection"), 1, GL_FALSE, glm::value_ptr(Renderer::m_Camera->GetProjectionMatrix()));
		glUniformMatrix4fv(glGetUniformLocation(m_Shader->getShaderProgram(), "u_view"), 1, GL_FALSE, glm::value_ptr(Renderer::m_Camera->GetViewMatrix()));
	}

}