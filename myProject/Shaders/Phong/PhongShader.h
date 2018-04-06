#ifndef PHONG_SHADER_H
#define PHONG_SHADER_H

#include "../Shader.h"
#include "../../Core/Camera/Camera.h"

class PhongShader : public Shader
{
public:
	PhongShader(const std::string& vertexFile, const std::string& fragmentFile);
	~PhongShader();

	void updateUniforms(const glm::mat4& worldMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);

	void setCamera(Camera * cam);
private:
	Camera * cam;
};

#endif