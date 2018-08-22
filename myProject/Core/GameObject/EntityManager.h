#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include <vector>
#include <map>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	bool addModel(const std::string& path, const std::string& keyName = "Model");
	bool addEntity(const std::string& entityName = "Entity", const std::string& modelName = "Model");

	Entity* getEntity(const std::string& entityName);
	const std::vector<Entity*> getEntities();
	const std::vector<std::string> getAllEntityNames();

private:
	std::map< std::string, Model*> modelMap;
	std::map< std::string, Entity*> entities;
};

#endif