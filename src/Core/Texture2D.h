#pragma once
#include <GL/glew.h>

#include <ostream>
#include <functional>
#include "Config.h"

class Texture2D
{
private:
	unsigned int textureOBJ[15];
	
	std::string sourceImagePath;
	int imgWidth, imgHeight, imgNumOfNormalChannels;
	unsigned char* imgData;
	bool hasAlphaChannel;

public:

	Texture2D(const std::string& sourceImagePath, int numOfUnits=1);

	void Bind();
	void Unbind();

private:
	void FindType(const std::string& fileName);
};