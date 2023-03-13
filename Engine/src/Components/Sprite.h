#pragma once
#include <glew.h>

#include <functional>
#include "../Core/Globals.h"
#include <ostream>

namespace KozaCore
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

		class Atlas
		{
		public:
			Atlas(const std::string& sourceImagePath, const std::string& parseData, int parseMode=NULL);

		private:
			int mAtlasDimensions[2];
			int mSpriteDimensions[2];
		};

	private:
		void FindType(const std::string& fileName);
	};

	constexpr std::uint8_t PARSE_RAW = 0x01;
	constexpr std::uint8_t PARSE_FILE = 0x02;

}