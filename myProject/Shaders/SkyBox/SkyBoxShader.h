#ifndef SKYBOXSHADER_H
#define SKYBOXSHADER_H

#include "..\Shader.h"
#include "..\..\Core\Camera\Camera.h"

class SkyBoxShader : public Shader
{
public:
	SkyBoxShader();
	~SkyBoxShader();

	void updateUniforms(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
};

#endif