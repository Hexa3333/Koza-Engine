#include "Sprite.h"
#include "stb_image.h"

#include <iostream>

using namespace Kz_Core;

Sprite::Sprite(const std::string& sourceImagePath, int numOfUnits /*(For multiple textures)*/)
{
	imgData = stbi_load(sourceImagePath.c_str(), &imgWidth, &imgHeight, &imgNumOfNormalChannels, 0);
	if (imgData == NULL)
	{
		imgData = stbi_load("missing.jpg", &imgWidth, &imgHeight, &imgNumOfNormalChannels, 0);
		std::cerr << "Sprite instance " << this << " has failed to read a sprite(s)." << std::endl;
		hasAlphaChannel = false; // "missing.jpg" does not have an alpha channel.
	}
	else
	{
		FindType(sourceImagePath);
	}

	glGenTextures(1, &textureOBJ[0]);
	glBindTexture(GL_TEXTURE_2D, textureOBJ[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, GL_FALSE, hasAlphaChannel ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imgData);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(imgData);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Sprite::Bind() { glBindTexture(GL_TEXTURE_2D, textureOBJ[0]); }
void Sprite::Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

Sprite::~Sprite()
{
	glDeleteTextures(1, &textureOBJ[0]);
}

void Sprite::FindType(const std::string& fileName)
{
	std::string type;

	int dotIndex = 0;
	char c;
	for (int i = fileName.length(); i > 0; i--)
	{
		c = fileName[i];
		if (c == '.')
		{
			dotIndex = i;
			goto esc;
		}
	}
esc:
	for (int i = dotIndex + 1; i < fileName.length(); i++)
	{
		type += fileName[i];
	}


	if (type == "jpg")
	{
		hasAlphaChannel = false;
	}
	else if (type == "png")
	{
		hasAlphaChannel = true;
	}
}