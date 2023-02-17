#pragma once
#include <glew.h>

#include <functional>
#include "../Core/Globals.h"
#include <ostream>

namespace Koza_Core
{
	class Sprite
	{
	private:
		unsigned int textureOBJ[15];
	
		int imgWidth, imgHeight, imgNumOfNormalChannels;
		unsigned char* imgData;
		bool hasAlphaChannel;

	public:
		Sprite() = default;
		Sprite(const std::string& sourceImagePath, int numOfUnits=1);
		~Sprite();

		void Bind();
		void Unbind();

	private:
		void FindType(const std::string& fileName);
	};
}


/*
class Sprite
{
private:
	Sprite* image;
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
	Sprite(Sprite* sourceImage, float size, GLenum drawType = GL_STATIC_DRAW);

	void Render(Shader* pShader);


	void SetTransform(glm::vec3 pVecTransform);
};
*/