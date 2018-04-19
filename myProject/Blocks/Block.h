#ifndef BLOCK_H
#define BLOCK_H


#include "glm.hpp"
#include "glew.h"
#include "..\Graphics\Model\Mesh.h"
#include "..\Shaders\Phong\PhongShader.h"
#include "..\Core\Camera\Camera.h"

#include "../Graphics/Textures/Texture.h"

enum SIDE { FRONT, BACK, LEFT, RIGHT, TOP, BOT };

class Block
{
public:
	Block(const std::string & texPath);
	~Block();

	void render(const Camera& cam);

private:
	void QuadInit();
	
	PhongShader shader;
	Mesh mesh;
	Texture texture;

	glm::vec3 position;

	glm::mat4 worldMatrix;

	GLuint vao, vbo, ebo;

private:
	

};

#endif