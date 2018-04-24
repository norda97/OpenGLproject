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

	bool addModel(const std::string& path, const std::string& keyName = "default");
	bool addEntity(const std::string& entityName = "default", const std::string& modelName = "default");

	Entity* getEntity(const std::string& entityName);
	const std::vector<Entity*> getEntities();
	const std::vector<std::string> getAllEntityNames();

private:
	std::map< std::string, Model*> modelMap;
	std::map< std::string, Entity*> entities;
};

#endif