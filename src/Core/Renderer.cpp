#include "Renderer.h"
#include <algorithm>

void Renderer::Init()
{

}

void Renderer::Run()
{
	for (auto obj : Entities) {
		obj->Render(obj->m_Shader);
	}
}
