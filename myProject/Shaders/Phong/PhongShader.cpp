#include "PhongShader.h"

PhongShader::PhongShader()
	: Shader("Phong/phong.vs", "Phong/phong.fs")
{
}


PhongShader::~PhongShader()
{
}

void PhongShader::updateUniforms(const glm::mat4& worldMatrix)
{

}
