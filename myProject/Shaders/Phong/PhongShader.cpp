#include "PhongShader.h"

PhongShader::PhongShader()
	: Shader("Phong/phong.vs", "Phong/phong.fs")
{
}


PhongShader::~PhongShader()
{

}

void PhongShader::updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projViewMatrix)
{
	this->useProgram();

	this->loadMatrix4(3, worldMatrix);
	this->loadMatrix4(4, projViewMatrix);

	glUseProgram(0);

}
