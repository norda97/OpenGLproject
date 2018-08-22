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
		for (unsigned i = 0; i < entities.size(); i++)
		{
			entities[i]->loadOBJ(phongShader.getID());
		}
	}
}

Texture* Renderer::renderTexture(Shaders shader, const std::vector<Entity*>& entities, const Camera & cam)
{
	this->frameBuffer.bind();
	
	glClearColor(0.1f, 0.5f, 0.1f, 1.0f);	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	this->render(shader, entities, cam);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	return this->frameBuffer.getTexture(0);
}

void Renderer::render(Shaders shader, const std::vector<Entity*>& entities, const Camera & cam)
{
	if (shader == Shaders::phong)
	{
		phongShader.updateUniforms(entities[0]->getWorldMatrix(), cam.getProj() * cam.getView());
		phongShader.useProgram();
		phongShader.loadVector3(5, cam.getPosition());
		phongShader.loadVector3(6, glm::vec3(10.0, 10.0, 10.0));

		for (unsigned i = 0; i < entities.size(); i++)
		{
			phongShader.loadMatrix4(3, entities[i]->getWorldMatrix());
			entities[i]->render();
		}

		glUseProgram(0);
	}
}

void Renderer::renderParticles(const std::vector<ParticleEmitter*>& emitters, const Camera & cam)
{
}
