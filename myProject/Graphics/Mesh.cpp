#include "Mesh.h"

#include "..\Loaders\ObjLoader.h"
#include "glew.h"

Mesh::Mesh(const std::string & path)
{
	loadOBJ(path, vertices);

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
}

void Mesh::render()
{
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glBindVertexArray(0);
}

void Mesh::loadGPU(const  GLuint & shaderID)
{
	glUseProgram(shaderID);

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

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glUseProgram(0);
}
