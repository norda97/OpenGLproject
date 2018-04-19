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

	void addModel(const std::string& path, const std::string& keyName = "default");
	bool addEntity(const std::string& modelName = "default");

	const std::vector<Entity*> & getEntities();

private:
	std::map< std::string, Model*> modelMap;
	std::vector<Entity*> entities;
};

#endif