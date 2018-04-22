#include "Renderer.h"
#include "..\..\Shaders\Shader.h"


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
		phongShader.updateUniforms(entities[0]->getWorldMatrix(), cam.getProj() * cam.getView());
		phongShader.loadVector3(5, cam.getPosition());
		phongShader.useProgram();


		for (int i = 0; i < entities.size(); i++)
		{
			phongShader.loadMatrix4(3, entities[i]->getWorldMatrix());
			entities[i]->render();
		}

		glUseProgram(0);
	}
}
