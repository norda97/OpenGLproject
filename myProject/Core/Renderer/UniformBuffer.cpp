#include "UniformBuffer.h"


UniformBuffer::UniformBuffer(const std::string & name, const GLuint & shader, const GLuint & bindingPoint)
{
	this->bindingpoint = bindingPoint;
	this->index = glGetUniformBlockIndex(shader, name.c_str());
	glUniformBlockBinding(shader, this->index, this->bindingpoint);
	glGenBuffers(1, &this->id);
}

UniformBuffer::~UniformBuffer()
{
	glDeleteBuffers(1, &this->id);
}

void UniformBuffer::setData(const void * data, const GLuint & size)
{
	glBindBuffer(GL_UNIFORM_BUFFER, this->id);
	glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, this->bindingpoint, this->id);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void UniformBuffer::setSubData(const void * data, const GLuint & size, const GLuint & offset)
{
	glBindBuffer(GL_UNIFORM_BUFFER, this->id);
	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
