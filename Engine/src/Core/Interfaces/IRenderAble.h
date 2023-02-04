#pragma once
#include "../Shader.h"

namespace Koza_Core
{
	class IRenderAble
	{
	public:
		bool IsBeingRendered = true;
		void ToggleRender() { IsBeingRendered = !IsBeingRendered; }

		Shader* m_Shader;
		IRenderAble(Shader* shader) : m_Shader(shader) {}
		virtual void Render(Shader* shader) = 0;
	};
}