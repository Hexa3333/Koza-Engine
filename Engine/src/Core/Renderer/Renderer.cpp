#include "Renderer.h"
#include "../Application.h"
#include "../Game.h"
#include <algorithm>
#include <iostream>

namespace KozaCore
{
	std::vector<IRenderAble*> Renderer::Entities;
	unique_ptr<Camera> m_Camera;

	void Renderer::Init()
	{
		m_Camera = make_unique<Camera>(0.0f, Application::WindowWidth, 0.0f, Application::WindowHeight, -1.0f, 1.0f);
		Entities.reserve(200 * sizeof(IRenderAble*));
	}

	void Renderer::Run()
	{
		for (auto& obj : Entities) 
		{
			if (obj->IsBeingRendered) obj->Render();

			obj->TickUniforms(obj->m_Shader);
		}
	}

	void Renderer::Kill()
	{
		Entities.clear();
	}

}