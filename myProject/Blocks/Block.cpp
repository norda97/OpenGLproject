#include "Block.h"

#include "gtc\matrix_transform.hpp"

Block::Block(const std::string & texPath)
	:	texture(texPath, true)
{
	this->worldMatrix = glm::mat4(1.0f);
	//this->mesh.loadGPU(this->shader.getID());
}


Block::~Block()
{
	glDeleteVertexArrays(1, &this->vao);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Block::render(const Camera& cam)
{
	//this->shader.updateUniforms(glm::mat4(1.0f), cam.getView(), cam.getProj());
	//this->shader.useProgram();

	this->texture.loadTexture(0);

	this->mesh.render();
}

void Block::QuadInit()
{

}

