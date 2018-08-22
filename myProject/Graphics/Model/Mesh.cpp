#include "Mesh.h"

#include "glew.h"

UniformBuffer* Mesh::ubo = nullptr;

Mesh::Mesh()
{
	
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
	
	if (ubo != nullptr)
	{
		delete ubo;
		ubo = nullptr;
	}
}

void Mesh::render()
{
	this->texture.loadTexture(0);
	glBindVertexArray(this->vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Mesh::loadGPU(const  GLuint & shaderID)
{
	glUseProgram(shaderID);

	if (ubo == nullptr)
	{
		ubo = new UniformBuffer("material", shaderID, 0);
		ubo->setData(&this->material, sizeof(material));
	}

	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertexStruct), &vertices[0], GL_STATIC_DRAW);
	//send in Position to location 0 and  Uvs 1
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), BUFFER_OFFSET(sizeof(GLfloat) * 3));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), BUFFER_OFFSET(sizeof(GLfloat) * 6));

	//glGenBuffers(1, &this->ebo);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), &indicies[0], GL_STATIC_DRAW);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glUseProgram(0);
}

void Mesh::addVertex(vertexStruct vertex)
{
	vertices.push_back(vertex);
}

void Mesh::setMaterial(const Material & mat)
{
	this->material = mat;
}

void Mesh::setTexture(const std::string & path, const bool & useMIPMAP)
{
	this->texture.setTexture(path, useMIPMAP);
}

void Mesh::updateMaterial()
{
	if (ubo != nullptr)
	{
		ubo->setSubData(&this->material, sizeof(material), 0);
	}
}
