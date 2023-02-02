#pragma once

#include "glew.h"
#include <string>
#include <vector>

namespace Kz_Core
{
	class Shader
	{
	private:

		unsigned int vertexShader, fragmentShader;
		unsigned int shaderProgram;

	public:
		Shader();
		Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
		void Use();
		~Shader();

		template<typename T> void sendUniform(const std::string& variableName, T value);

	public:
		void Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void CreateFromFile(const std::string& vertexFilePath, const std::string& fragmentFilePath);
	
		unsigned int getShaderProgram();
	};
}
