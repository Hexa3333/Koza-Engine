#pragma once

#include "GL/glew.h"
#include <string>

namespace Kz
{
	class Shader
	{

	private:
		unsigned int vertexShader, fragmentShader;
		unsigned int shaderProgram;

	public:
		Shader();
		Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
		~Shader();

		void Use();

		template<typename T> void sendUniform(const std::string& variableName, T value);

	public:
		void Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void CreateFromFile(const std::string& vertexFilePath, const std::string& fragmentFilePath);
	
		unsigned int getShaderProgram();
	};
}
