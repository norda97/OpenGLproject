#ifndef SKYBOX_H
#define SKYBOX_H

#include "..\..\Core\Camera\Camera.h"
#include "..\..\Shaders\Shader.h"
#include "..\..\Shaders\SkyBox\SkyBoxShader.h"
#include <vector>

class Skybox
{
public:
	Skybox(const std::vector<std::string> path);
	~Skybox();

	void render(const Camera & cam);

private:
	SkyBoxShader shader;
	unsigned textureID;
	unsigned vao, vbo, ebo;

	void loadCubeMapTexture();

	GLfloat skyboxVertices[24] = {        
		// front
		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,
	};

	GLuint indicies[36] = {
	
		// front
		0, 2, 1,
		2, 0, 3,
		// back
		4, 5, 6,
		6, 7, 4,
		// right
		1, 6, 5,
		1, 2, 6,
		// left
		0, 4, 7,
		7, 3, 0,
		// top
		2, 3, 7,
		2, 7, 6,
		// bot
		0, 1, 4,
		5, 4, 1,
	};
};

#endif // !SKYBOX_H
