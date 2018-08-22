#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Mesh.h"
#include "Material.h"


class Model
{
public:
	Model();
	~Model();

	void addMesh(Mesh * mesh);
	void render();

	void loadGPU(const GLuint & shaderID);
private:
	std::vector<Mesh*> meshes;
};

#endif