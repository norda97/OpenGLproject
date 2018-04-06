#ifndef BLOCK_H
#define BLOCK_H


#include "glm.hpp"
#include "glew.h"
#include "../Mesh.h"

#include "../Graphics/Textures/Texture.h"

enum SIDE { FRONT, BACK, LEFT, RIGHT, TOP, BOT };

class Block
{
public:
	Block(const std::string & texPath);
	~Block();

	void render();
	void loadGPU(const GLuint& shaderID);

private:
	void QuadInit();

	Mesh mesh;
	Texture texture;

	glm::vec3 position;

	glm::mat4 worldMatrix;

	GLuint vao, vbo, ebo;

private:
	GLfloat verticies[40] = {
		// front
		-1.0, -1.0,  1.0,		0.0f, 0.0f,
		1.0, -1.0,  1.0,		1.0f, 0.0f,
		1.0,  1.0,  1.0,		1.0f, 1.0f,
		-1.0,  1.0,  1.0,		0.0f, 1.0f,
		// back
		-1.0, -1.0, -1.0,		0.0f, 0.0f,
		1.0, -1.0, -1.0,		0.0f, 1.0f,
		1.0,  1.0, -1.0,		1.0f, 1.0f,
		-1.0,  1.0, -1.0,		1.0f, 0.0f

	};

	GLushort indicies[36] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3
	};

};

#endif