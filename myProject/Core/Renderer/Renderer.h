#ifndef RENDERER_H
#define RENDERER_H

#include "..\Entity\Entity.h"
#include "..\..\Core\Camera\Camera.h"
#include "..\..\Shaders\Phong\PhongShader.h"
#include "FrameBuffer.h"



//forward declaretions
class ParticleEmitter;
class ParticleRenderer;

class Renderer
{
public:
	Renderer();
	~Renderer();

	enum Shaders { phong };
	void setShader(Shaders shader, const std::vector<Entity*>& entities);
	Texture* renderTexture(Shaders shader, const std::vector<Entity*>& entities, const Camera& cam);
	void render(Shaders shader, const std::vector<Entity*>& entities, const Camera& cam);
	void renderParticles(const std::vector<ParticleEmitter*>& emitters, const Camera& cam);

private:
	PhongShader phongShader;
	FrameBuffer frameBuffer;

	ParticleRenderer * particleRenderer;
};

#endif