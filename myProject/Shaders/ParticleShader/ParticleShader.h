#ifndef PARTICLESHADER_H
#define PARTICLESHADER_H

#include "../Shader.h"

class ParticleShader : public Shader
{
public:
	ParticleShader();
	~ParticleShader();

	void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projViewMatrix);
};

#endif