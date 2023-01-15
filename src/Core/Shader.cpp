#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

/*
*	TODO: 
*	Use of "#shader" pragmas for seperating
* fragment and vertex shaders.
* 
* 
* Shader IDs ?
* 
*	CONSTRUCTORS SHOULD NOT CREATE. THIS WILL BE USEFUL
* FOR GAMEOBJECT INSTANTIATION
* 
*/

Shader::Shader(){}

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

	if (!vertexFile.is_open() || !fragmentFile.is_open())
	{
		std::cerr << "[!] Failed to read file containing shader source at: [ID\'s not implemented yet]" << std::endl;
	}

	vertexSS << vertexFile.rdbuf();
	fragmentSS << fragmentFile.rdbuf();

	Create(vertexSS.str(), fragmentSS.str());
}

Shader::~Shader()
{
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Use(){ glUseProgram(shaderProgram); }

// TODO:
template<typename T>
inline void Shader::sendUniform(const std::string& variableName, T value)
{
	std::cout << "It\'s type = " << typeid(value) << std::endl;
}



// -- -- -- -- -- -- -- -- -- -- -- -- --

unsigned int Shader::getShaderProgram()
{
	return shaderProgram;
}