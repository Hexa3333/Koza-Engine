#pragma once
#include "../Shader.h"

namespace Kz_Core
{
	class IRenderAble
	{
	public:
		Shader* m_Shader;
		IRenderAble(Shader* shader) : m_Shader(shader) {}
		virtual void Render(Shader* shader) = 0;
	};
}