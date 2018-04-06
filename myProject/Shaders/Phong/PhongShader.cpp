#include "PhongShader.h"

PhongShader::PhongShader(const std::string& vertexFile, const std::string& fragmentFile)
	: Shader(vertexFile, fragmentFile)
{
}


PhongShader::~PhongShader()
{
}

void PhongShader::updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix)
{
	this->useProgram();
	this->loadMatrix4(3, worldMatrix);
	this->loadMatrix4(4, projectionMatrix * viewMatrix );

	glUseProgram(0);
}

void PhongShader::setCamera(Camera * cam)
{
	this->cam = cam;
}
