#ifndef PHONG_SHADER_H
#define PHONG_SHADER_H

#include "../Shader.h"
#include "../../Core/Camera/Camera.h"

class PhongShader : public Shader
{
public:
	PhongShader();
	~PhongShader();

	void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& projViewMatrix);
};

#endif