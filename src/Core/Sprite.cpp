#include "Sprite.h"
#include <iostream>

Sprite::Sprite(Texture2D* sourceImage, GLenum drawType)
{
	image = sourceImage;
	m_Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Sprite::Render(Shader* pShader)
{
	image->Bind();
	m_Mesh->Render(pShader);
	image->Unbind();
}