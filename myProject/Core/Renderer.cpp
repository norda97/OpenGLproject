#include "Renderer.h"
#include "..\Shaders\Shader.h"


Renderer::Renderer()
{
	
}


Renderer::~Renderer()
{
}

void Renderer::setShader(Shaders shader, const std::vector<Entity*>& entities)
{
	if (shader == Shaders::phong)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->loadOBJ(phongShader.getID());
		}
	}
}

void Renderer::render(Shaders shader, const std::vector<Entity*>& entities, const Camera & cam)
{
	if (shader == Shaders::phong)
	{
		phongShader.useProgram();

		phongShader.loadMatrix4(4, cam.getProj() * cam.getView());

		for (int i = 0; i < entities.size(); i++)
		{
			phongShader.loadMatrix4(3, entities[i]->getWorldMatrix());
			entities[i]->render();
		}

		glUseProgram(0);
	}
}
