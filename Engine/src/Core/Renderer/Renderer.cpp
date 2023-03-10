#include "Renderer.h"
#include "../Game.h"
#include <algorithm>
#include <iostream>
using namespace Koza_Core;

std::vector<IRenderAble*> Renderer::Entities;

void Renderer::Init()
{
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
