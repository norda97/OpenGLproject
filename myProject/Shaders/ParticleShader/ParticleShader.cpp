#include "ParticleShader.h"



ParticleShader::ParticleShader()
	: Shader("ParticleShader/particle.vs", "ParticleShader/particle.fs")
{
}


ParticleShader::~ParticleShader()
{
}

void ParticleShader::updateUniforms(const glm::mat4 & worldMatrix, const glm::mat4 & projViewMatrix)
{
	this->useProgram();

	this->loadMatrix4(1, worldMatrix);
	this->loadMatrix4(2, projViewMatrix);

	glUseProgram(0);
}
