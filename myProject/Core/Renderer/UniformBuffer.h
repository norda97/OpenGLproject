#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H


#include "glew.h"
#include <string>

class UniformBuffer
{
public:
	UniformBuffer(const std::string& name, const GLuint& shader, const GLuint& bindingPoint);
	~UniformBuffer();

	void setData(const void* data, const GLuint& size);
	void setSubData(const void* data, const GLuint& size, const GLuint& offset);
private:
	GLuint bindingpoint, index, id;
};

#endif