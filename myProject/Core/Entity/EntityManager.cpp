#include "EntityManager.h"

#include "..\..\Loaders\ObjLoader.h"

EntityManager::EntityManager()
{
	this->addModel("./Resources/Mesh/Cube/cube.obj");
	this->addEntity();
}


EntityManager::~EntityManager()
{
	for (const auto& pair : this->entities)
		delete pair.second;

	for (const auto& pair : modelMap)
		delete pair.second;
}

bool EntityManager::addModel(const std::string & path, const std::string& keyName)
{
	bool foundName = false;

	if (this->modelMap.find(keyName) == this->modelMap.end()) 
		this->modelMap.insert(std::make_pair(keyName, loadOBJ(path)));
	else
		foundName = true;

	return foundName;
}

bool EntityManager::addEntity(const std::string& entityName, const std::string& modelName)
{
	bool foundName = false;

	
	if (this->entities.find(entityName) == this->entities.end()) 
		this->entities.insert(std::make_pair(entityName, new Entity(this->modelMap[modelName])));
	else 
		foundName = true;

	return foundName;
}

Entity * EntityManager::getEntity(const std::string & entityName)
{
	return this->entities[entityName];
}

const std::vector<Entity*> EntityManager::getEntities()
{
	std::vector<Entity*> allEntities;
	for (const auto& pair : this->entities)
		allEntities.push_back(pair.second);

	return allEntities;
}

const std::vector<std::string> EntityManager::getAllEntityNames()
{
	std::vector<std::string> allNames;
	for (const auto& pair : this->entities)
		allNames.push_back(pair.first);

	return allNames;
}


