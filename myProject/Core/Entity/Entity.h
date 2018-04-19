#ifndef ENTITY_H
#define ENTITY_H

#include "../../Graphics/Model/Model.h"
#include "../Camera/Camera.h"

class Entity
{
public:
	Entity(Model * model, const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f));
	~Entity();

	void render();
	void loadOBJ(const GLuint & shaderID);
	const glm::mat4& getWorldMatrix();
private:
	glm::vec3 position;
	Model* model;
};

#endif