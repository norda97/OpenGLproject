#ifndef RENDERER_H
#define RENDERER_H

#include "..\Entity\Entity.h"
#include "..\..\Core\Camera\Camera.h"
#include "..\..\Shaders\Phong\PhongShader.h"
class Renderer
{
public:
	Renderer();
	~Renderer();

	enum Shaders { phong };
	void setShader(Shaders shader, const std::vector<Entity*>& entities);
	void render(Shaders shader, const std::vector<Entity*>& entities, const Camera& cam);

private:
	PhongShader phongShader;
	
};

#endif