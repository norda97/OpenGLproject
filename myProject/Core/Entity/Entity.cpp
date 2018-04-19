#include "Entity.h"

#include "gtc\matrix_transform.hpp"

Entity::Entity(Model * model, const glm::vec3& position)
{
	this->model = model;
}

Entity::~Entity()
{
	//delete model;
}

void Entity::render()
{
	model->render();
}

void Entity::loadOBJ(const GLuint & shaderID)
{
	this->model->loadGPU(shaderID);
}

const glm::mat4 & Entity::getWorldMatrix()
{
	return glm::translate(glm::mat4(1.0f), position);
}


