#pragma once
#include "../Renderer/Renderer.h"
#include "../../Components/Transform.h"
#include "../../Components/Shader.h"

namespace KozaCore
{
	class IRenderAble
	{
	public:
		bool IsBeingRendered = true;
		void ToggleRender() { IsBeingRendered = !IsBeingRendered; }

		Transform transform;
		Shader* m_Shader;
		IRenderAble(Shader* shader) : m_Shader(shader) {}
		virtual void Render() = 0;

		void TickUniforms(Shader* shader);
	

		IRenderAble() = delete;
		IRenderAble(const IRenderAble&) = delete;
		IRenderAble(IRenderAble&&) = delete;
	};
}