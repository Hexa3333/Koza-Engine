#pragma once

#include "glew.h"
#include <string>
#include <vector>

namespace Koza_Core
{
	class Shader
	{
	private:
		unsigned int vertexShader, fragmentShader;
		unsigned int shaderProgram;

	public:
		Shader() = default;
		Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
		void Use();
		~Shader();

		void Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		void CreateFromFile(const std::string& vertexFilePath, const std::string& fragmentFilePath);

		unsigned int getShaderProgram();
	};
}
