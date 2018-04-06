#ifndef MESH_H
#define MESH_H

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#include <vector>
#include "glm.hpp"
#include "Shaders\Shader.h"
#include "Loaders\ObjLoader.h"


class Mesh
{
public:
	Mesh(const std::string & path);
	~Mesh();

	void render();
	void loadGPU(const GLuint & shaderID);

private:
	GLuint vao, vbo, ebo;
	std::vector<vertexStruct> vertices;
};

#endif
