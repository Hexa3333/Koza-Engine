#include "Renderer.h"
#include <algorithm>
using namespace Koza_Core;


void Renderer::Init()
{

}

void Renderer::Run()
{
	for (auto obj : Entities) {
		obj->Render(obj->m_Shader);
	}
}

void Renderer::Kill()
{
	Entities.clear();
}