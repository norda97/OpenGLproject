#include "EntityManager.h"

#include "..\..\Loaders\ObjLoader.h"

EntityManager::EntityManager()
{
	this->addModel("./Resources/Mesh/Cube/cube.obj");
	this->addEntity();
}


EntityManager::~EntityManager()
{
	for (int i = 0; i < this->entities.size(); i++)
	{
		delete this->entities[i];
	}

	for (const auto& pair : modelMap)
	{
		if(modelMap.size() != 0)
		{ 
			delete pair.second;
			modelMap.erase(pair.first);
		}
	}
}

void EntityManager::addModel(const std::string & path, const std::string& keyName)
{
	this->modelMap.insert(std::make_pair(keyName ,loadOBJ(path)));
}

bool EntityManager::addEntity(const std::string & modelName)
{
	bool foundName;
	
	this->entities.push_back(new Entity(this->modelMap[modelName]));

	return false;
}

const std::vector<Entity*>& EntityManager::getEntities()
{
	return this->entities;
}


