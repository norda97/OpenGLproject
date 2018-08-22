#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void destroy();

private:
	static std::vector<std::unique_ptr<GameObject>> gameObjects;
};

#endif