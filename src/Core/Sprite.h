#pragma once

#include "Mesh.h"
#include "Texture2D.h"

class Sprite
{
private:
	Texture2D* image;
	Mesh* m_Mesh;

	float svertices[32] = {
		//    VERTICES                          // COLORS                           // TEXTURE
		 1.0f,  1.0f, 0.0f,		1.0f, 1.0f,      // top right
		 1.0f, -1.0f, 0.0f,		1.0f, 0.0f,      // bottom right
		-1.0f, -1.0f, 0.0f,		0.0f, 0.0f,      // bottom left
		-1.0f, 1.0f, 0.0f,		0.0f, 1.0f        // top left
	};
	unsigned int sindices[6] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

public:
	Sprite(Texture2D* sourceImage, float size, GLenum drawType = GL_STATIC_DRAW);

	void Render(Shader* pShader);
};