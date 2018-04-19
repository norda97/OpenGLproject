#ifndef MESH_H
#define MESH_H

#define BUFFER_OFFSET(i) ((char *)NULL + (i))


#include <vector>
#include "glm.hpp"
#include "..\..\Shaders\Shader.h"
#include "Material.h"


struct vertexStruct
{
	GLfloat position[3];
	GLfloat normals[3];
	GLfloat uv[2];
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	void render();
	void loadGPU(const GLuint & shaderID);
	void addVertex(vertexStruct vertex);
	void setMaterial(const Material & mat);
private:
	GLuint vao, vbo, ebo;
	std::vector<vertexStruct> vertices;
	Material material;
};

#endif