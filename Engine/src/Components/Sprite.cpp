#include "Sprite.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace KozaCore;

Sprite::Sprite(const std::string& sourceImagePath, int numOfUnits /*(For multiple textures)*/)
{
	imgData = stbi_load(sourceImagePath.c_str(), &imgWidth, &imgHeight, &imgNumOfNormalChannels, 0);
	if (imgData == NULL)
	{
		std::cerr << "Sprite instance " << this << " has failed to read a sprite(s)." << std::endl;
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
}

void Sprite::Bind() { glBindTexture(GL_TEXTURE_2D, textureOBJ[0]); }
void Sprite::Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

Sprite::~Sprite()
{
	glDeleteTextures(1, &textureOBJ[0]);
}

static int FindXInString(const char* str)
{
	int xSeperationIndex;
	for (int i = 0; i < sizeof(str); i++)
	{
		char c = str[i];
		if (c == 'x' || c == 'X')
		{
			xSeperationIndex = i;
			break;
		}
	}
	return xSeperationIndex;
}

Sprite::Atlas::Atlas(const std::string& sourceImagePath, const std::string& parseData, int parseMode)
{
	if (parseMode & PARSE_FILE)
	{
		FILE* fp = NULL;
		fp = fopen(parseData.c_str(), "r");

		if (fp == NULL)
		{
			std::cout << "Failed to read Sprite Atlas Data at: " << this << std::endl;
			return;
		}
		
		char dimensionsFull[9];
		char dimensionsPerSprite[9];

		fgets(dimensionsFull, sizeof(dimensionsFull), fp);
		fgets(dimensionsPerSprite, sizeof(dimensionsPerSprite), fp);
		fclose(fp);
		
		int dimFullXsep = FindXInString(dimensionsFull);
		int dimPerSpriteXsep = FindXInString(dimensionsPerSprite);
		
		mAtlasDimensions[0] = std::stoi(dimensionsFull);
		mAtlasDimensions[1] = std::stoi(&dimensionsFull[dimFullXsep + 1]);

		mSpriteDimensions[0] = std::stoi(dimensionsPerSprite);
		mSpriteDimensions[1] = std::stoi(&dimensionsPerSprite[dimPerSpriteXsep + 1]);

		std::cout << "Atlas Dimensions (" << mAtlasDimensions[0] << ", " << mAtlasDimensions[1] << ")\n";
		std::cout << "Atlas Dimensions (" << mSpriteDimensions[0] << ", " << mSpriteDimensions[1] << ")\n";
	}

	else
	{

	}

}


void Sprite::FindType(const std::string& fileName)
{
	char* type = (char*)malloc(5);

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