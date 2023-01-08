#pragma once

#include <string>

namespace utils
{
std::string FindFileTypeWString(const std::string& fileName)
{
	std::string type;
	
	int dotIndex = -1;
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

	return type;
}
	
}