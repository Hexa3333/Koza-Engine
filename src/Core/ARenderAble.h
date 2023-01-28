#pragma once
#include "Shader.h"
class ARenderAble
{
public:
	Shader* m_Shader;
	ARenderAble(Shader* shader) : m_Shader(shader) {}
	virtual void Render(Shader* shader) = 0;
};