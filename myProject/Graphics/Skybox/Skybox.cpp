#include "Skybox.h"
#include "..\Textures\CubeMap.h"



Skybox::Skybox(const std::vector<std::string> cubeMapPath)
	:	textureID(loadCubeMap(cubeMapPath))
{
	shader.useProgram();
	//Generate VAO and VBO and store cube in VBO
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(this->skyboxVertices), &this->skyboxVertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	

	//Generate EBO for indicies
	glGenBuffers(1, &this->ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), &indicies[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glUseProgram(0);
}

Skybox::~Skybox()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
}

void Skybox::render(const Camera & cam)
{
	glDepthMask(GL_FALSE);
	this->shader.updateUniforms(glm::mat4(glm::mat3(cam.getView())), cam.getProj());
	this->shader.useProgram();

	this->loadCubeMapTexture();
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glDrawElements(GL_TRIANGLES, sizeof(this->indicies) / sizeof(GLuint), GL_UNSIGNED_INT, 0);

	glDepthMask(GL_TRUE);

	glUseProgram(0);
}

void Skybox::loadCubeMapTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->textureID);
	glActiveTexture(0);
}
