#include "Shader.h"
#include "../Core/Globals.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace KozaCore;

/*
*	TODO: 
*	Use of "#shader" pragmas for seperating
* fragment and vertex shaders.
* 
* Shader IDs ?
* 
*/

Shader::Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
{
	CreateFromFile(vertexFilePath, fragmentFilePath);
}

void Shader::Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	const char* vSource = vertexShaderSource.c_str();
	const char* fSource = fragmentShaderSource.c_str();

	glShaderSource(vertexShader, 1, &vSource, nullptr);
	glCompileShader(vertexShader);

	glShaderSource(fragmentShader, 1, &fSource, nullptr);
	glCompileShader(fragmentShader);

	int vertexSuccessResult;
	char vertexInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccessResult);

	if (!vertexSuccessResult)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, vertexInfoLog);
		std::cerr << "Failed Vertex Shader Compilation: " << vertexInfoLog << std::endl;
	}

	int fragmentSuccessResult;
	char fragmentInfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccessResult);

	if (!fragmentSuccessResult)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentInfoLog);
		std::cerr << "Failed Fragment Shader Compilation: " << fragmentInfoLog << std::endl;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	int shaderSuccessResult;
	char shaderInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderSuccessResult);

	if (!shaderSuccessResult)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, shaderInfoLog);
		std::cerr << "Shader linking failed: " << shaderInfoLog << std::endl;
	}

}

void Shader::CreateFromFile(const std::string& vertexFilePath, const std::string& fragmentFilePath)
{
	std::ifstream vertexFile(vertexFilePath);
	std::ifstream fragmentFile(fragmentFilePath);
	
	std::ostringstream vertexSS;
	std::ostringstream fragmentSS;

	if (!vertexFile.is_open())
	{
		std::cerr << "[!] Failed to read file containing a vertex shader source." << std::endl
			<< "	->	[*] Reverting to the default vertex shader source." << std::endl;
		vertexSS << KozaCore::DEFAULT_VERTEX_SHADER;
	}
	else vertexSS << vertexFile.rdbuf();
	
	if (!fragmentFile.is_open())
	{
		std::cerr << "[!] Failed to read file containing a fragment shader source." << std::endl
				  << "	->	[*] Reverting to the default fragment shader source." << std::endl;
		fragmentSS << KozaCore::DEFAULT_FRAGMENT_SHADER;
	}
	else fragmentSS << fragmentFile.rdbuf();

	Create(vertexSS.str(), fragmentSS.str());
}

Shader::~Shader()
{
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteProgram(shaderProgram);
}

void Shader::Use(){ glUseProgram(shaderProgram); }

unsigned int Shader::getShaderProgram()
{
	return shaderProgram;
}