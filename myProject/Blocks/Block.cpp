#include "Block.h"

#include "gtc\matrix_transform.hpp"

Block::Block(const std::string & texPath)
	:	mesh("Resources/Mesh/Cube/cube.obj"),
		texture(texPath, true)
{
	this->worldMatrix = glm::mat4(1.0f);
}


Block::~Block()
{
	glDeleteVertexArrays(1, &this->vao);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Block::render()
{
	this->texture.loadTexture(0);

	this->mesh.render();
}

void Block::QuadInit()
{

}

void Block::loadGPU(const GLuint& shaderID)
{
	this->mesh.loadGPU(shaderID);
}
