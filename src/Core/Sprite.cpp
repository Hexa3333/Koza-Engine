#include "Sprite.h"
#include <iostream>

Sprite::Sprite(Texture2D* sourceImage, float size, GLenum drawType)
{
	image = sourceImage;
	m_Mesh = new Mesh(svertices, sindices, sizeof(svertices), sizeof(sindices));
	m_Mesh->model = glm::scale(m_Mesh->model, glm::vec3(size));
}


void Sprite::Render(Shader* pShader)
{
	image->Bind();
	m_Mesh->Render(pShader);
	image->Unbind();
}