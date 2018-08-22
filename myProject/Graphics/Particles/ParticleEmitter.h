#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include <vector>

#include "Particle.h"
#include "..\Model\Model.h"


class ParticleEmitter
{
public:
	ParticleEmitter(const glm::vec3& position = { 0.0f, 0.0f, 0.0f }, unsigned ParticlesPerSecond = 10);
	~ParticleEmitter();

	void setPosition(const glm::vec3& position);
	const glm::vec3& getPosition();

	void setVelocity(const glm::vec3& velocity = { 0.0f, 1.0f, 0.0f });
	void setColor(const glm::vec3& color = { 1.0f, 1.0f, 1.0f });
	void setLife(const float& life = 3);
	void setRotation(const float& rotation = 0.0f);
	void setScale(const float& scale = 1.0f);
	void setGravity(const float& gravity = -1.0f);

	void update(float dt);

private:
	std::vector<Particle> particles;
	glm::vec3 position, color, velocity;
	float life, rotation, scale, gravity, particlesPerSec;

	Model* model;
	bool useModel;
};

#endif