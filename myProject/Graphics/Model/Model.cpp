#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
	for (int i = 0; i < this->meshes.size(); i++)
	{
		delete this->meshes[i];
	}
}

void Model::addMesh(Mesh * mesh)
{
	this->meshes.push_back(mesh);
}

void Model::render()
{
	for (int i = 0; i < this->meshes.size(); i++)
	{
		this->meshes[i]->updateMaterial();
		this->meshes[i]->render();
	}
}

void Model::loadGPU(const GLuint & shaderID)
{
	for (int i = 0; i < this->meshes.size(); i++)
	{
		this->meshes[i]->loadGPU(shaderID);
	}
}
