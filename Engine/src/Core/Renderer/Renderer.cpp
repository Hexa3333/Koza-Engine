#include "Renderer.h"
#include <algorithm>
using namespace Koza_Core;

std::vector<IRenderAble*> Renderer::Entities;

void Renderer::Init()
{

}

void Renderer::Run()
{
	for (auto obj : Entities) 
	{
		if (obj->IsBeingRendered) obj->Render(obj->m_Shader);
		obj->TickUniforms(obj->m_Shader);
	}
}

void Renderer::Kill()
{
	for (auto obj : Entities) delete obj;
	Entities.clear();
}
