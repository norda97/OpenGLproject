#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include "gtc\type_ptr.hpp"

Shader::Shader(const std::string & vertexFile, const std::string & fragmentFile)
{
	this->m_id = this->loadShaders(vertexFile, fragmentFile);
	this->useProgram();
}

Shader::~Shader()
{
	glDeleteProgram(this->m_id);
}

void Shader::useProgram() const
{
	glUseProgram(this->m_id);
}

const GLuint Shader::getID() const
{
	return this->m_id;
}

void Shader::loadInt(GLuint location, int value)
{
	glUniform1i(location, value);
}

void Shader::loadFloat(GLuint location, float value)
{
	glUniform1f(location, value);
}

void Shader::loadVector2(GLuint location, const glm::vec2 & vect)
{
	glUniform2f(location, vect.x, vect.y);
}

void Shader::loadVector3(GLuint location, const glm::vec3 & vect)
{
	glUniform3f(location, vect.x, vect.y, vect.z);
}

void Shader::loadVector4(GLuint location, const glm::vec4 & vect)
{
	glUniform4f(location, vect.x, vect.y, vect.z, vect.w);
}

void Shader::loadMatrix4(GLuint location, const glm::mat4 & matrix)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::updateUniforms()
{
}

GLuint Shader::loadShaders(const std::string & vertexShader, const std::string & fragmentShader)
{
	std::string vertexSource = this->loadFile(PATH + vertexShader);
	std::string fragmentSource = this->loadFile(PATH + fragmentShader);

	auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
	auto fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

	auto shaderID = linkProgram(vertexShaderID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return shaderID;
}

GLuint Shader::linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	auto id = glCreateProgram();

	glAttachShader(id, vertexShaderID);
	glAttachShader(id, fragmentShaderID);

	glLinkProgram(id);

	return id;
}

GLuint Shader::compileShader(const GLchar * source, GLenum shaderType)
{
	auto shaderID = glCreateShader(shaderType);

	glShaderSource(shaderID, 1, &source, nullptr);
	glCompileShader(shaderID);

	GLint isSuccess = 0;
	GLchar infoLog[1024];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);
	if (!isSuccess) {
		glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);

		if(shaderType == GL_VERTEX_SHADER)
			std::cout << "Unable to load vertex shader: " + std::string(infoLog) << std::endl;
		else
			std::cout << "Unable to load fragment shader: " + std::string(infoLog) << std::endl;
	}

	return shaderID;
}

const std::string Shader::loadFile(const std::string & shaderFile)
{
	std::ifstream shaderStream;
	std::stringstream strStream;
	
	shaderStream.open(shaderFile);

	if (shaderStream.fail())
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		return 0;
	}

	strStream << shaderStream.rdbuf();

	shaderStream.close();

	std::string finalOut = strStream.str();

	return finalOut;
}
