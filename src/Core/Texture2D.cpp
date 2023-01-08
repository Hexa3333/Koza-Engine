#include "Texture2D.h"
#include "stb/stb_image.h"

#include <iostream>

Texture2D::Texture2D(const std::string& sourceImagePath, int numOfUnits /*(For multiple textures)*/)
{
	imgData = stbi_load(sourceImagePath.c_str(), &imgWidth, &imgHeight, &imgNumOfNormalChannels, 0);
	this->sourceImagePath = sourceImagePath;
	FindType(sourceImagePath);

	glGenTextures(1, &textureOBJ[0]);
	glBindTexture(GL_TEXTURE_2D, textureOBJ[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (imgData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, GL_FALSE, hasAlphaChannel ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imgData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else std::cerr << "Failed to read texture!" << std::endl;

	stbi_image_free(imgData);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() { glBindTexture(GL_TEXTURE_2D, textureOBJ[0]); }
void Texture2D::Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }


void Texture2D::FindType(const std::string& fileName)
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