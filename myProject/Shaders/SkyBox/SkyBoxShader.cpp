#include "SkyBoxShader.h"

#include "gtc\matrix_transform.hpp"

SkyBoxShader::SkyBoxShader()
	: Shader("SkyBox/skybox.vs", "SkyBox/skybox.fs")
{
}


SkyBoxShader::~SkyBoxShader()
{
}

void SkyBoxShader::updateUniforms(const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix)
{

	this->useProgram();

	this->loadMatrix4(1, viewMatrix);
	this->loadMatrix4(2, projectionMatrix);

	glUseProgram(0);
}
